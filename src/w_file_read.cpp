#include "w_file_read.h"

_INIT_LOG();

void get_w_file_size(int *w_file_size, char *buff, const int file_size);

int w_file_read(wchar_t **arr_ptr, int *w_file_size, const char *directory)
{
    assert(arr_ptr);
    assert(directory);
    _OPEN_LOG("logs/wide_file_read.log");

    char *buff = NULL;
    int file_size = 0;

    LOG("> reading file into a buffer:\n");
    int error = file_read(&buff, &file_size, directory);
    if (error)
    {
        LOG("[error]>>> file reading error\n");
        _CLOSE_LOG();
        return error;
    }

    LOG("> size of wchar: %ld\n", sizeof(wchar_t));
    LOG("> detecting wide buff size:\n");
    int wide_file_size = 0;
    get_w_file_size(&wide_file_size, buff, file_size);

    LOG("> allocating memory for wchar buffer:\n");
    wchar_t *wbuff = (wchar_t *)calloc(wide_file_size + 1, sizeof(wchar_t));
    if (!wbuff)
    {
        LOG("[error]>>> wide char memory allocation error\n");
        free(buff);
        _CLOSE_LOG();
        return WCHAR_MEM_ALC_ERR;
    }
    
    int shift = mbstowcs(wbuff, buff, file_size);
    if (shift == -1)
    {
        LOG("[error]>>> wide char reading error\n");
        _CLOSE_LOG();
        free(buff);
        free(wbuff);
        return W_CHAR_READ_ERR;
    }
    
    if (w_file_size)
        *w_file_size = wide_file_size;

    *arr_ptr = wbuff;

    free(buff);
    _CLOSE_LOG();
    return NO_ERR;
}

void get_w_file_size(int *w_file_size, char *buff, const int file_size)
{
    assert(buff);
    assert(w_file_size);

    int wide_buff_size = 0;
    
    for (int pos = 0; pos < file_size;)
    {
        switch (buff[pos] & 0xF0)
        {
        case 0xF0:  pos += 4;   break;
        case 0xE0:  pos += 3;   break;

        default:
        if (buff[pos] & 0x80)   pos += 2;
        else                    pos++;
        }

        wide_buff_size++;
    }
    
    *w_file_size = wide_buff_size;
    LOG("> wide char buffer size: %d\n", wide_buff_size);
}