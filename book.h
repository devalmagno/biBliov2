typedef struct {
    char bookName[41];
    char authorName[41];
    char bookGenre[41];
    double bookPrice;
    int ID;
    int exibir;
} book;

book Book[1000];

void registerBook();      
void openBookArchive();
void closeBookArchive();  
