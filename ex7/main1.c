#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n;
    int lotto[7];
    int i, j, num, repeat;
    char date[50];

    srand(time(NULL));

    printf("歡迎光臨長庚樂透彩購買機台\n");
    printf("請問您要買幾組樂透彩：");
    scanf("%d", &n);

    if (n < 1 || n > 5)
    {
        printf("輸入錯誤，請輸入 1~5 組！\n");
        return 0;
    }

    FILE *fp = fopen("lotto.txt", "w");

    if (fp == NULL)
    {
        printf("檔案開啟失敗！\n");
        return 1;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    strftime(date, sizeof(date), "%a %b %d %H:%M:%S %Y", t);

    fprintf(fp, "========== lotto649 ==========\n");
    fprintf(fp, "= %s =\n", date);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 7; j++)
        {
            do
            {
                num = rand() % 69 + 1;
                repeat = 0;

                for (int k = 0; k < j; k++)
                {
                    if (lotto[k] == num)
                    {
                        repeat = 1;
                        break;
                    }
                }

            } while (repeat == 1);

            lotto[j] = num;
        }

        fprintf(fp, "[%d]: ", i + 1);

        for (j = 0; j < 7; j++)
        {
            fprintf(fp, "%02d ", lotto[j]);
        }

        fprintf(fp, "\n");
    }

    fprintf(fp, "========== csie@CGU ==========\n");

    fclose(fp);

    printf("以為您購買的 %d 組樂透組合輸出至 lotto.txt\n", n);

    return 0;
}
