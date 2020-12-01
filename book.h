typedef struct {
    char bookName[41];
    char authorName[41];
    char bookGenre[41];
    double bookPrice;
    int ID;
    int exibir;
    int buyNumber;
} book;

book Book[100];

void registerBook();      
void openBookArchive();
void closeBookArchive();  
void readValues();
void showBooks();