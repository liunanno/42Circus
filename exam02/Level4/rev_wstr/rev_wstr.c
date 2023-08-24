#include <unistd.h>
#include <stdlib.h>

// 判断字符是否为空格或制表符
int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

// 反转字符串
void reverse_string(char *str, int len)
{
    int i = 0;
    int j = len - 1;
    while (i < j) {
        char tmp = str[i];
        str[i] = str[j];
        str[j] = tmp;
        i++;
        j--;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        write(1, "\n", 1);
        return 0;
    }

    char *str = argv[1];
    int len = 0;
    int i = 0;

    // 计算字符串长度
    while (str[len]) {
        len++;
    }

    // 反转整个字符串
    reverse_string(str, len);

    while (i < len) {
        // 跳过空格和制表符
        while (i < len && is_space(str[i])) {
            i++;
        }

        // 记录单词起始位置
        int start = i;

        // 找到单词结束位置
        while (i < len && !is_space(str[i])) {
            i++;
        }

        // 记录单词结束位置
        int end = i - 1;

        // 反转单词
        reverse_string(str + start, end - start + 1);

        // 输出单词和空格
        write(1, str + start, end - start + 1);
        if (i < len) {
            write(1, " ", 1);
        }
    }

    // 输出换行符
    write(1, "\n", 1);

    return 0;
}