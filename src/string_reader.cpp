#include "include/string_reader.h"

_INIT_LOG();

void take_string_number(int *string_number, wchar_t *buff);

int read_strings(string_t **strs, int *string_number, wchar_t *buff, const int buff_size)
{
    assert(strs);
    assert(string_number);
    assert(buff);

    _OPEN_LOG("logs/stringerizator.log");

    LOG("> detecting nubmer of strings:");
    int strs_num = 0;
    take_string_number(&strs_num, buff);    
    if (strs_num == 1)
    {
        LOG("[warning]>>> file has only 1 string\n");
        printf("[warning]>>> file has only 1 string, programm will not be executed\n");
        free(buff);
        _CLOSE_LOG();
        return ONLY_ONE_STR;
    }

    LOG("> starting string array creation\n");
    string_t *stroki = (string_t *)calloc(strs_num, sizeof(string_t));
    if (!stroki)
    {
        LOG("[error]>>> string array memory alocation error\n");
        free(buff);
        _CLOSE_LOG();
        return STR_ARR_MEM_ALC_ERR;
    }

    stroki[0].str_ptr = buff;
    for (int str = 1; str < strs_num; str++)
    {
        stroki[str].str_ptr = wcschr(stroki[str - 1].str_ptr, '\0') + 1; 
        stroki[str - 1].str_len = stroki[str].str_ptr - stroki[str - 1].str_ptr;
        if(*stroki[str].str_ptr == '\n')
            stroki[str].str_ptr += 1;
        
        LOG("> string with length: %d found\n", stroki[str - 1].str_len);
    }
    stroki[strs_num - 1].str_len = &buff[buff_size + 1] - stroki[strs_num - 1].str_ptr;
    LOG("> string with length: %d found\n", stroki[strs_num - 1].str_len);
    LOG("> string array created successfully\n");

    *strs = stroki;
    if (string_number)
        *string_number = strs_num;

    _CLOSE_LOG();
    return 0;
}

void take_string_number(int *string_number, wchar_t *buff)
{
    assert(string_number);
    assert(buff);

    int pos = 0;
    int str_num = 0;
    while (buff[pos] != '\0')
    {
        if (buff[pos] == '\n')
        {
            LOG("> \\n founded, it must be an LF system\n");
            buff[pos] = '\0';
            str_num++;
        }
        else if (buff[pos] == '\r')
        {
            LOG("> \\r founded, it must be an CRLF system\n");
            buff[pos] = '\0';
            pos++;
            str_num++;
        }
        
        pos++;
    }

    if (buff[pos - 1] != '\n' && buff[pos - 1] != '\0')
        str_num++;
    
    LOG(">> total number of strings is: %d\n", str_num);
    *string_number = str_num;

    return;
}