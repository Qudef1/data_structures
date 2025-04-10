#include "qsort.cpp"
#include "Picture.h"
using namespace std;
//bin search in text file 
//proverki
void sozdaniepic(Picture &pic)
{
    cout << "enter picture name ";
    cin.getline(pic.name, 20);

    cout << "enter artist ";
    cin.getline(pic.artist, 20);

    cout << "enter year ";
    cin >> pic.year;
    cin.ignore();

    cout << "enter style of picture ";
    cin.getline(pic.style, 20);

    cout << "enter length and height ";
    cin >> pic.length >> pic.height;
}

void prosmotr(Picture &stud, const char* filename);
void prosmotrtxt(const char* path);

void pokaz(const Picture &pic)
{
    cout << "Name: " << pic.name << endl;
            cout<< "Artist: "<<pic.artist<<endl;
            cout << "Year: " << pic.year << endl;
            cout<< "Style: " << pic.style<<endl;
            cout<<"Length: "<<pic.length<<" Height: "<<pic.height<<endl;
            cout << endl;
}

void ydalenie(Picture &pic, const char* filename, const char* name,const char* artist)
{
    bool flag = false;
    ifstream fin;
    ofstream fout;
    fin.open(filename, ios::binary);
    fout.open("temp.bin", ios::binary);
    if (!fin.is_open() || !fout.is_open())
    {
        cout << "error";
        fout.close();
        fin.close();
    }
    else
    {
        while (fin.read(reinterpret_cast<char *>(&pic), sizeof(Picture)))
        {
            if (strcmp(pic.name, name) != 0&&strcmp(pic.artist, artist)!=0)
            {
                fout.write(reinterpret_cast<char *>(&pic), sizeof(Picture));
            }
            else
            {
                flag = true;
            }
        }
        if (flag)
        {
            cout << "removed " << name << endl;
        }
        else
        {
            cout << "no such picture" << endl;
        }
    }
    fin.close();
    fout.close();
    remove(filename);
    rename("temp.bin", filename);
}

void redact(Picture &pic, const char* filename, const char* lastname,const char* artist)
{
    bool flag = false;
    ifstream fin;
    ofstream fout;
    fin.open(filename, ios::binary);
    fout.open("temp.bin", ios::binary);
    if (!fin.is_open() || !fout.is_open())
    {
        cout << "error";
        fout.close();
        fin.close();
    }
    else
    {
        while (fin.read(reinterpret_cast<char *>(&pic), sizeof(Picture)))
        {
            if (strcmp(pic.name, lastname) == 0 && strcmp(pic.artist,artist )==0)
            {
                
                cout << "enter new height, old one: " << pic.height << endl;
                cin >> pic.height;
                cout << "enter new length, old one: " << pic.length << endl;
                cin>>pic.length;
                cout << "enter new year, old one: " << pic.year << endl;
                cin>>pic.year;
                cout << "enter new style, old one: " << pic.style << endl;
                cin.getline(pic.style,sizeof(pic.style));
                fout.write(reinterpret_cast<char *>(&pic), sizeof(Picture));
                flag = true;
            }
            else
            {
                fout.write(reinterpret_cast<char *>(&pic), sizeof(Picture));
            }
        }
        if (flag)
        {
            cout << "changed " << lastname << endl;
        }
        else
        {
            cout << "nothing to change" << endl;
        }
    }
    fin.close();
    fout.close();
    remove(filename);
    rename("temp.bin", filename);
}

void prosmotrtxt(const char* path)
{
    ifstream fin;
    char line[256];
    fin.open(path);
    while (fin.getline(line, sizeof(line)))
    {
        cout << line << endl;
    }
    fin.close();
}

void insertionSort(Picture &pic, const char* path){
    ifstream fin;
    ofstream fout;
    fin.open(path, ios::binary);
    fout.open("year.txt", ios::out);
    if (!fout.is_open() || !fin.is_open())
    {
        fout.close();
        fin.close();
        cout << "error"<<endl;
    }
    else{
        int size = 0;
        Picture picptr[10];
        while (fin.read(reinterpret_cast<char *>(&pic), sizeof(Picture)))
        {
            picptr[size] = pic;
            size++;
        }
        insertionSort(picptr,size);
        for (int i = 0; i < size; i++)
            {
                pokaz(picptr[i]);
                fout << "Name: " << picptr[i].name << endl;
                fout<< "Artist: "<<picptr[i].artist<<endl;
                fout << "Year: " << picptr[i].year << endl;
                fout<< "Style: " << picptr[i].style<<endl;
                fout<<"Length: "<<picptr[i].length<<" Height: "<<picptr[i].height<<endl;
                fout << endl;
            }
    }
}

void selectionSort(Picture& pic,const char* path){
    
    ifstream fin;
    ofstream fout;
    fin.open(path, ios::binary);
    fout.open("name.txt", ios::out);
    if (!fout.is_open() || !fin.is_open())
    {
        fout.close();
        fin.close();
        cout << "error"<<endl;
    }
    else
    {
        int size = 0;
        Picture picptr[10];
        while (fin.read(reinterpret_cast<char *>(&pic), sizeof(Picture)))
        {
            picptr[size] = pic;
            size++;
        }
        selectionSort(picptr,size);
        for(int i = 0;i<size;i++){
            pokaz(picptr[i]);
            fout << "Name: " << picptr[i].name << endl;
            fout<< "Artist: "<<picptr[i].artist<<endl;
            fout << "Year: " << picptr[i].year << endl;
            fout<< "Style: " << picptr[i].style<<endl;
            fout<<"Length: "<<picptr[i].length<<" Height: "<<picptr[i].height<<endl;
            fout << endl;
        }
        
    }
    fin.close();
    fout.close();
}
void linSearch(Picture &pic, const char* artist,const char* path){
    ifstream fin;
    ofstream fout;
    fin.open(path, ios::binary);
    fout.open("linsearch.txt",ios::out);
    if (!fin.is_open())
    {
        
        fin.close();
        cout << "error"<<endl;
        throw "File is not opened";
    }
    else
    {

        int size = 0;
        Picture picptr[20];
        while (fin.read(reinterpret_cast<char *>(&pic), sizeof(Picture)))
        {
            picptr[size] = pic;
            size++;
        }
        for(int i = 0;i<size;i++){
            if(strcmp(picptr[i].artist,artist)==0){
                pokaz(picptr[i]);
                fout << "Name: " << picptr[i].name << endl;
                fout<< "Artist: "<<picptr[i].artist<<endl;
                fout << "Year: " << picptr[i].year << endl;
                fout<< "Style: " << picptr[i].style<<endl;
                fout<<"Length: "<<picptr[i].length<<" Height: "<<picptr[i].height<<endl;
                fout << endl;
            }
        }
        fin.close();
        fout.close();
        
    }
}
void lengthSort(Picture &pic, const char* path)
{
    ifstream fin;
    ofstream fout;
    fin.open(path, ios::binary);
    fout.open("length.txt", ios::out);
    if (!fout.is_open() || !fin.is_open())
    {
        fout.close();
        fin.close();
        cout << "error"<<endl;
    }
    else
    {
        int size = 0;
        Picture picptr[10];
        while (fin.read(reinterpret_cast<char *>(&pic), sizeof(Picture)))
        {
            picptr[size] = pic;
            size++;
        }
        bubbleSort(picptr,size);for(int i = 0;i<size;i++){
            pokaz(picptr[i]);
        fout << "Name: " << picptr[i].name << endl;
            fout<< "Artist: "<<picptr[i].artist<<endl;
            fout << "Year: " << picptr[i].year << endl;
            fout<< "Style: " << picptr[i].style<<endl;
            fout<<"Length: "<<picptr[i].length<<" Height: "<<picptr[i].height<<endl;
            fout << endl;
        }
        
    }
    fin.close();
    fout.close();
}

void saveTofile(Picture &pic, const char* filename)
{
    ofstream fout;
    fout.open(filename, ios::binary | ios::app);
    if (!fout.is_open())
    {
        cout << "error";
    }
    else
    {
        fout.write((char *)&pic, sizeof(Picture));
    }
    fout.close();
}

void prosmotr(Picture &pic, const char* filename)
{
    ifstream fin;
    fin.open(filename, ios::binary);
    if (!fin.is_open())
    {
        cout << "error"<<endl;
    }
    else
    {
        int counter = 1;
        while (fin.read(reinterpret_cast<char *>(&pic), sizeof(Picture)))
        {
            cout << counter << ". " << endl;
            pokaz(pic);
            counter++;
        }
    }
    fin.close();
}

void BinarySearch(Picture &pic,const char* filename){
    ifstream fin;
    fin.open(filename,ios::binary);
    if(!fin.is_open()){
        fin.close();
        std::cout<<"error"<<std::endl;
    }
    else{
        Picture picptr[20];
        int size = 0;
        while (fin.read(reinterpret_cast<char *>(&pic), sizeof(Picture)))
        {
            picptr[size] = pic;
            size++;
        }
        insertionSort(picptr,size);
        int year;
        cout<<"enter year to search for"<<endl;
        cin>>year;
        cout<<(binSearch(picptr,year,size)?"there is picture, that was written in this year":"there is not")<<endl;
        
} 
    fin.close();    
}
void betweenYears(Picture& pic,const char* filename){
    int startYear,endYear;
    std::cout<<"enter gaps"<<std::endl;
    std::cin>>startYear>>endYear;
    ifstream fin;
    ofstream fout;
    fout.open("betweenYears.txt",ios::out);
    fin.open(filename,ios::binary);

    if(!fin.is_open()){
        fin.close();
        std::cout<<"error"<<std::endl;
    }
    else{
        Picture picptr[20];
        int size = 0;
        while (fin.read(reinterpret_cast<char *>(&pic), sizeof(Picture)))
        {
            if(pic.year<=endYear&&pic.year>=startYear){
            picptr[size] = pic;
            size++;
        }
        }
        insertionSort(picptr,size);
        for(int i = 0;i<size;i++){
            pokaz(picptr[i]);
            fout << "Name: " << picptr[i].name << endl;
            fout<< "Artist: "<<picptr[i].artist<<endl;
            fout << "Year: " << picptr[i].year << endl;
            fout<< "Style: " << picptr[i].style<<endl;
            fout<<"Length: "<<picptr[i].length<<" Height: "<<picptr[i].height<<endl;
            fout << endl;
        }

} 
    fout.close();
    fin.close();    
}
void SearchFortheBiggest(Picture &pic, const char* filename) {
    ifstream fin;
    ofstream fout;
    fout.open("threeBiggest.txt");
    fin.open(filename, ios::binary);
    if (!fin.is_open()) {
        fin.close();
        std::cout << "error" << std::endl;
        return;
    }

    Picture picptr[20]; 
    int size = 0;

    while (fin.read(reinterpret_cast<char*>(&pic), sizeof(Picture))) {
        picptr[size] = pic;
        size++;
    }
    fin.close();

    int outputCount = (size < 3) ? size : 3;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            int areaI = picptr[i].height * picptr[i].length;
            int areaJ = picptr[j].height * picptr[j].length;
            if (areaI < areaJ) {
                
                Picture temp = picptr[i];
                picptr[i] = picptr[j];
                picptr[j] = temp;
            }
        }
    }

    
    std::cout << "The three biggest pictures in the gallery are: " << endl;
    for (int i = 0; i < outputCount; i++) {
        
        pokaz(picptr[i]);
        fout << "Name: " << picptr[i].name << endl;
        fout<< "Artist: "<<picptr[i].artist<<endl;
        fout << "Year: " << picptr[i].year << endl;
        fout<< "Style: " << picptr[i].style<<endl;
        fout<<"Length: "<<picptr[i].length<<" Height: "<<picptr[i].height<<endl;
        fout << endl;
        
    }
    fout.close();
}

void divideByStyles(Picture &pic, const char* filename) {
    ifstream fin;
    ofstream fout;
    fout.open("styles.txt",ios::out);
    fin.open(filename, ios::binary);
    if (!fin.is_open()) {
        cout << "error" << endl;
        return;
    }

    const int MAX_PICTURES = 100; 
    Picture pictures[MAX_PICTURES];
    int pictureCount = 0;

    
    while (fin.read(reinterpret_cast<char*>(&pic), sizeof(Picture)) && pictureCount < MAX_PICTURES) {
        pictures[pictureCount] = pic;
        pictureCount++;
    }
    fin.close();

    
    const int MAX_STYLES = 20;
    char styles[MAX_STYLES][50];
    int styleCount = 0;

    
    for (int i = 0; i < pictureCount; i++) {
        bool styleExists = false;
        for (int j = 0; j < styleCount; j++) {
            if (strcmp(pictures[i].style, styles[j]) == 0) {
                styleExists = true;
                break;
            }
        }
        if (!styleExists) {
            strcpy(styles[styleCount], pictures[i].style);
            styleCount++;
        }
    }

    for (int i = 0; i < styleCount; i++) {
        cout << "Style: " << styles[i] << endl;
        fout << "Style: " << styles[i] << endl;


        Picture stylePictures[MAX_PICTURES];
        int stylePictureCount = 0;

        
        for (int j = 0; j < pictureCount; j++) {
            if (strcmp(pictures[j].style, styles[i]) == 0) {
                stylePictures[stylePictureCount] = pictures[j];
                stylePictureCount++;
            }
        }

        
        selectionSort(stylePictures,stylePictureCount);

        
        for (int j = 0; j < stylePictureCount; j++) {
            pokaz(stylePictures[j]);
            fout << "Name: " << stylePictures[j].name << endl;
            fout<< "Artist: "<<stylePictures[j].artist<<endl;
            fout << "Year: " << stylePictures[j].year << endl;
            fout<< "Style: " << stylePictures[j].style<<endl;
            fout<<"Length: "<<stylePictures[j].length<<" Height: "<<stylePictures[j].height<<endl;
            fout << endl;
        }
        
    }
    fout.close();
}
int main()
{
    cout<<"Welcome to my gallery you can:"<<endl<<"-------------------------------------------"<<endl;
    char path[30] = "gallery.bin";
    bool exitToken = true;
    
    while (exitToken)
    {
        char lastname[50] = " ";
        char artist[50] = "";
        Picture pic;
        int x;
        cout<<"-------------------------------------------"<<endl;
        cout << "1-sozdanie faila\n2-prosmotr\n3-dobavlenie" << endl
             << "4-nayti kartiny po avtory\n"
            << "5-ydalenie\n6-redaktirovanie\n7-by year\n"
             << "8-by name in alphabetical order\n9-by width\n10-search for between years\n11-search for picture,that was written on special year\n12-search for the 3 biggest picture" << endl<<
             "13-divide the gallery by styles"<<endl<<"0-exit"<<endl;
             cout<<"-------------------------------------------"<<endl;
        cin >> x;
        cin.ignore();
        switch (x)
        {
        case 1:
            cout << "enter filename to create file" << endl;
            cin.getline(path, sizeof(path));
            cout << "file for gallery information " << path << " has been successfully created";
            break;
        case 2:
            prosmotr(pic, path);
            break;
        case 3:
            sozdaniepic(pic);
            saveTofile(pic, path);
            break;
        case 4:
            char temp[50];
            cout<<"enter author to search for"<<std::endl;
            cin.getline(temp,50);
            cout <<"see pictures by this author in the text-file linsearch.txt"<<endl;
            linSearch(pic,temp,path);
            break;
        case 5:
            prosmotr(pic, path);
            cout << "enter name of a picture" << endl;
            cin.getline(lastname, sizeof(lastname));
            cout<<"enter artist that wrote this picture";
            cin.getline(artist,sizeof(artist));
            ydalenie(pic, path, lastname,artist);
            break;
        case 6:
            cout << "enter name of a picture" << endl;
            cin.getline(lastname, sizeof(lastname));
            cout<<"enter artist that wrote this picture";
            cin.getline(artist,sizeof(artist));
            redact(pic, path, lastname,artist);
            break;
        case 7:
            insertionSort(pic,path);
            break;
        case 8:
            selectionSort(pic,path);
            break;
        case 9:
            lengthSort(pic,path);
            break;
        case 10:
            betweenYears(pic,path);
            break;
        case 11:
            BinarySearch(pic,path);
            break;
        case 12:
            SearchFortheBiggest(pic,path);
            break;
        case 13:
            divideByStyles(pic,path);
            break;
        case 0:
            exitToken = false;
            break;
        default:
            cout << "try again" << endl;
        }
    }
    return 0;
}