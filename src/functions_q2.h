#define ef                                                                                                 \
    {                                                                                                      \
        0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094, 0.06966,                   \
        0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07707, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, \
        0.02758, 0.00978, 0.02360, 0.00150, 0.01974, 0.00074};

#define MAXLENGTH 10000
int offset(char c);
int *create_freq_table();
void add_letters(int *freq_table, char *string);
int letter_count(char *line);
int encode(char c, int shift);
double chi_sq(int shift, int n, int *text_freq);
int encode_shift(char *string, int *text_freq, int chiBool);
int to_decode(int shift);
int file_size(FILE *fp);
struct data
{

    char shortString[24];
    double doubles[24];
    char longString[144];
    int integers[12];
};