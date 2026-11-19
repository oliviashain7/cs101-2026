
#include <stdio.h>
#include <stdlib.h>

typedef struct Books
{
    int id;
    int price;
    char title[100];
} book_t;

// 計算所有書籍的總價
int total_price(book_t books[], int n)
{
    int total = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        total += books[i].price;
    }

    return total;
}

// 輸出所有書籍資料
void list_books(book_t books[], int n)
{
    int i;

    printf("\n========== Book List ==========\n");

    for (i = 0; i < n; i++)
    {
        printf("ID: %d\n", books[i].id);
        printf("Price: %d\n", books[i].price);
        printf("Title: %s\n", books[i].title);
        printf("------------------------------\n");
    }
}

int main()
{
    book_t books[6] =
    {
        {1, 1000, "All the Light We Cannot See"},
        {2, 300, "The 38 Letters from J.D. Rockefeller to his son"},
        {3, 1000, "The Ballad of Songbirds and Snakes"},
        {4, 550, "Killers of the Flower Moon"},
        {5, 870, "Elon Musk"},
        {6, 1344, "Milk and Honey 12-Month 2024"}
    };

    int total;
    FILE *fp;

    // 將書籍資料寫入 Book.bin
    fp = fopen("Book.bin", "wb");

    if (fp == NULL)
    {
        printf("檔案開啟失敗！\n");
        return 1;
    }

    fwrite(books, sizeof(book_t), 6, fp);

    fclose(fp);

    // 計算所有書籍總價
    total = total_price(books, 6);

    // 輸出書籍資料
    list_books(books, 6);

    printf("Total Price: %d\n", total);

    return 0;
}
