#include <locale.h>
#include "include/string_reader.h"
#include "include/string_work.h"
#include "include/bsort.h"

_INIT_LOG();

int main(int argc, char **argv) 
{
    if (argc != 3)
    {
        printf("> number of arguments does not match needed (write input and output files)\n");
        return ARGC_ERR;
    }

    _OPEN_LOG("logs/onegin.log");
    wchar_t *buff = NULL;
    int size = 0;

    setlocale(LC_ALL, "ru_RU.UTF-8");

    W_LOG(L"> locale is sit, starting file-reading\n");
    int error = w_file_read(&buff, &size, argv[2]);
    if (error)
    {
        _CLOSE_LOG();
        return error;
    }
    
    W_LOG(L"> file was read, dumping read file into a log:\n");
    W_LOG(L"--------------------------------------------------------------------\n");
    W_LOG(L"%ls\n", buff);
    W_LOG(L"--------------------------------------------------------------------\n");
    int string_number   = 0;
    string_t *strs      = NULL;
    error = read_strings(&strs, &string_number, buff, size);
    if (error)
    {
        _CLOSE_LOG();
        return error;
    }
    
    LOG("> opening output file:\n");
    FILE *out = fopen(argv[1], "w");
    if (!out)
    {
        LOG("[error]>>> couldn't open output file\n");
        free(buff);
        free(strs);
        _CLOSE_LOG();
        return OUTPUT_OPN_ERR;
    }

    W_LOG(L"> sorting in alphabet order:\n");
    fwprintf(out, L"#sorting text in alphabet order:\n\n");
    bsort(strs, string_number, sizeof(string_t), str_cmp);
    string_print(out, strs, string_number);

    W_LOG(L"> sorting in reverse alphabet order:\n");
    fwprintf(out, L"\n#sorting in alphabet order from the end:\n\n");
    bsort(strs, string_number, sizeof(string_t), reverse_str_cmp);
    string_print(out, strs, string_number);

    W_LOG(L"> programm completed\n");
    fclose(out);
    free(strs);
    free(buff);
    _CLOSE_LOG();
}