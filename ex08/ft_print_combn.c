#include <unistd.h>
void func_write_array(char  *str, int num, int end, int n);
void func_make_array_and_check_ascending(int num, int end, int n);

void ft_print_combn(int n)
{
    int num;
    int break_num;
    int mul_ten;
    int num_pos;
    int temp;
    
    temp = n;
    break_num = 0;
    num = 0;
    mul_ten = 1;
    num_pos = n - 1; // if. n = 5 -> num_pos 4, 3, 2, 1
    while (num_pos >= 1) // 1234 --> num
    {
        num += (mul_ten * num_pos--);
        mul_ten *= 10;
    }
    mul_ten = 1;
    num_pos = 9;
    while (temp-- >= 0)
    {
        break_num += (num_pos-- * mul_ten);
        mul_ten *= 10;
    }
    while(num <= break_num)
    {
        func_make_array_and_check_ascending(num, break_num, n);
        num++;
    }
}

void func_make_array_and_check_ascending(int num, int end, int n)
{
    char    str[10];
    int     idx;
    int     end_idx;
    int     temp;
    int     flag;
    
    flag = 0;
    temp = num;
    end_idx = n - 1;
    idx = n - 1;
    while (idx >= 0)
    {
        str[idx--] = (temp % 10) + 48;
        temp /= 10;
    }
    idx = 0;
    while (idx < end_idx)
    {
        if(str[idx] >= str[idx + 1])
            flag = 1;
        idx++;
    }
    if (flag == 0)
        func_write_array(str, num, end, n);
}

void func_write_array(char  *str, int num, int end, int n)
{
    int     idx;
    int     idx_p;
    int     temp;
    
    temp = num;
    idx = n - 1;
    idx_p = 0;

    if (num == end)
    {
        while (idx_p < n)
            write(1, &str[idx_p++], 1);
        write(1, "\n", 1);
    }
    else
    {
        while (idx_p < n)
            write(1, &str[idx_p++], 1);
        write(1, ", ", 2);
    }
    return;
}

int	main(void)
{
	ft_print_combn(5);
	return (0);
}
