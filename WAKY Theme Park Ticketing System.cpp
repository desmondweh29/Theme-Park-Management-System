#include <iostream> // For cin and cout function
#include <iomanip> // For decimal manipulation
#include <stdlib.h> // For clear screen & exit
#include <cctype> // For checking STRING boolean
#include <sstream> // For converting STRING to INTEGER
#include <string> // For string length
#include <ctime> // For actual date
#include <vector> // For usage of vector
#define _WIN32_WINNT 0x0500 // For full screen
#include <windows.h> // For background and text colours

using namespace std;

//--------------------------------------Declaration of global variables-------------------------

    string anyKey;
    int anyKeyInt;
    string response;
    string selectionNumStr;
    int selectionNum;
    int looper2=0;


    // Variables for main menu
    string number;

    // Variables for adding account
    string username;
    string password;
    int createdDay;
    int createdMonth;
    int createdYear;

    // Variables for adding park
    string parkName;
    string inputParkName;
    int parkID;

    // Variables for adjusting ticket price
    string childTicketPriceStr;
    string adultTicketPriceStr;
    string seniorTicketPriceStr;
    int newChildTicketPrice;
    int newAdultTicketPrice;
    int newSeniorTicketPrice;
    int childTicketPrice = 70;
    int adultTicketPrice = 100;
    int seniorTicketPrice = 60;

   // Variables for adjusting promo 1
   string minPurchaseStr;
   string discountRateStr;
   int newMinPurchase;
   int newDiscountRate_1;
   int minPurchase = 3;
   int discountRate_1 = 30;

   // Variables for adjusting promo 2
   string minTotalPriceStr;
   string typeOfGiftStr ;
   string valueOfGiftStr;
   int minTotalPrice = 200;
   string typeOfGift = "FOOD";
   int valueOfGift = 50;
   int newMinTotalPrice;
   int newValueOfGift;

   // Variables for adjusting promo 3
   string eventName ="FELIZ NAVIDAD";
   string eventNameStr;
   string eventDayStr,eventMonthStr,eventYearStr;
   int eventDay,eventMonth,eventYear;
   int oldEventDay = 25;
   int oldEventMonth =12 ;
   int oldEventYear =2020;
   string discountRate2Str;
   int discountRate_2=15;
   int newDiscountRate_2;
   int currentDay,currentMonth,currentYear;

    // Variables for ticketing
    string numOfParksStr, parkIDStr;
    int numOfParks;
    string validOfExP;
    string validDayStr, validMonthStr, validYearStr;
    int validDay, validMonth, validYear;
    string numChildrenStr, numAdultsStr, numSeniorsStr;
    int numChildren, numAdults, numSeniors;
    stringstream parkIDList2Str;
    string parkIDList2;

    // Variables for payment1
    double subtotal;
    double priceOfExP;
    int discount;
    double totalPrice;
    string gifts;

    // Variables for payment2
    string typesOfCard;
    string nameOfCard;
    string cardNum;
    string expDateMonthStr,expDateYearStr;
    int expDateMonth, expDateYear;
    string cvv;

    // Variables for payment3
    int refNumInt;
    string refNumStr;
    int purchaseYear, purchaseMonth, purchaseDay;
    int numTickets;

//-----------------------------------Admin class-----------------------------------

class Admin {
    private:
        string newUsername;
        string newPassword;
        int newCreatedDay;
        int newCreatedMonth;
        int newCreatedYear;

    public:

        Admin (string username, string password,int createdDay,int createdMonth ,int createdYear){
            newUsername = username;
            newPassword = password;
            newCreatedDay=createdDay;
            newCreatedMonth=createdMonth;
            newCreatedYear=createdYear;
        }

        string getUsername() const {
            return newUsername;
        }

        string getPassword() const {
            return newPassword;
        }
        int getCreatedDay() const{
            return newCreatedDay;
        }

        int getCreatedMonth() const{
            return newCreatedMonth;
        }

        int getCreatedYear() const{
            return newCreatedYear;
        }


        void setUsername (string username){
            newUsername = username;
        }

        void setPassword (string password){
            newPassword = password;
        }

        void setCreatedDay (int createdDay){
            newCreatedDay=createdDay;
        }

        void setCreatedMonth (int createdMonth){
            newCreatedMonth=createdMonth;
        }

        void setCreatedYear (int createdYear){
            newCreatedYear=createdYear;
        }
};

//-----------------------------------Park class-----------------------------------

class Park {
    private:
        string newParkName;
        int newParkID;

    public:
        Park (string parkName, int parkID){
        newParkName = parkName;
        newParkID = parkID;
    }

    string getParkName()const {
        return newParkName;
    }

    int getParkID()const {
        return newParkID;
    }

    void setParkName (string parkName){
        newParkName = parkName;
    }

    void setParkID (int parkID){
        newParkID = parkID;
    }
};

//-----------------------------------Transaction history class-----------------------------------

class TransactionHistory {
    private:
        // Members variable
        string refNumStrRec;
        int refNumIntRec;
        int purchaseDayRec, purchaseMonthRec, purchaseYearRec;
        int numOfParksRec;
        string parkIDList2Rec;
        int numTicketsRec;
        string validOfExPRec;
        int validDayRec, validMonthRec, validYearRec;
        double totalPriceRec;
        string giftsRec;

    public:
             // Overload constructor
            TransactionHistory(string refNumStr, int refNumInt,
                                int purchaseDay, int purchaseMonth, int purchaseYear,
                                int numOfParks,
                                string parkIDList2,
                                int numTickets,
                                string validOfExP,
                                int validDay, int validMonth, int validYear,
                                double totalPrice,
                                string gifts){
                                refNumStrRec = refNumStr;
                                refNumIntRec = refNumInt;
                                purchaseDayRec = purchaseDay;
                                purchaseMonthRec = purchaseMonth;
                                purchaseYearRec = purchaseYear;
                                numOfParksRec = numOfParks;
                                parkIDList2Rec = parkIDList2;
                                numTicketsRec = numTickets;
                                validOfExPRec = validOfExP;
                                validDayRec = validDay;
                                validMonthRec = validMonth;
                                validYearRec = validYear;
                                totalPriceRec = totalPrice;
                                giftsRec = gifts;
                                }

        string getRefNumStr() const{
            return refNumStrRec;
        }
        int getRefNumInt() const{
            return refNumIntRec;
        }
        int getPurchaseDay() const{
            return purchaseDayRec;
        }
        int getPurchaseMonth() const{
            return purchaseMonthRec;
        }
        int getPurchaseYear() const{
            return purchaseYearRec;
        }
        int getNumOfParks() const{
            return numOfParksRec;
        }

        string getParkIDList2() const{
            return parkIDList2Rec;
        }

        int getNumTickets() const{
            return numTicketsRec;
        }
        string getValidOfExP() const{
            return validOfExPRec;
        }
        int getValidDay() const{
            return validDayRec;
        }
        int getValidMonth() const{
            return validMonthRec;
        }
        int getValidYear() const{
            return validYearRec;
        }
        double getTotalPrice() const{
            return totalPriceRec;
        }
        string getGifts() const{
            return giftsRec;
        }
};

//-----------------------------------Declaration of vectors-----------------------

    vector <Admin> List;
    vector <TransactionHistory> history;
    vector <Park> parkList;
    vector <int> parkIDList;

//-----------------------------------Boolean check-----------------------------------

bool isLetters(string input)
{
    for (int i=0;i<input.size();i++)
    {
        if (isalpha(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isNumbers(string input)
{
    for (int i=0;i<input.size();i++)
    {
        if (isdigit(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isSpace(string input)
{
    for (int i=0;i<input.size();i++)
    {
        if (isspace(input[i]))
        {
            return true;
        }
    }
    return false;
}

bool isPunct(string input)
{
    for (int i=0;i<input.size();i++)
    {
        if (ispunct(input[i]))
        {
            return true;
        }
    }
    return false;
}

// Same user name is not allowed
bool usernameCheck(const vector <Admin>& newList, string username){
    for (int i = 0; i < newList.size(); i++){
        if (username == newList[i].getUsername()){
                return false;
        }
    }return true;
}

// To check user name and password valid or not
bool adminCheck(const vector <Admin>& newList, string inputUsername, string inputPassword){
    for (unsigned int i = 0; i < newList.size(); i++){
        if (inputUsername == newList[i].getUsername()){
            if (inputPassword == newList[i].getPassword()){
                return true;
            }
        }
    }return false;
}

bool repetitionParkNameCheck (const vector <Park>& newParkList, string inputParkName){
    for (unsigned int i = 0 ; i < newParkList.size() ; i++){
        if (inputParkName == newParkList[i].getParkName()){
            return false;
        }
    }return true;
}

bool parkIDCheck(const vector <Park>& newParkList, int parkID){
    for (int i = 0; i < newParkList.size(); i++){
        if (parkID == newParkList[i].getParkID()){
                return true;
        }
    }return false;
}

bool repetitionParkIDCheck (const vector <int> &newParkIDList, int parkID ){
    for (unsigned int i = 0 ; i < newParkIDList.size() ; i++){
        if (parkID == newParkIDList [i]){
            return false;
        }
    }return true;
}

//Adjust promotion and gifts--------------------------

bool repetitionCheck(int minPurchase,int discountRate_1)
{
    if(minPurchase==newMinPurchase && discountRate_1==newDiscountRate_1 ){
        return false;
    }return true;

}

bool repetitionCheck2(int minTotalPrice,string typeOfGift,int valueOfGift)
{
    if(minTotalPrice==newMinTotalPrice && typeOfGift==typeOfGiftStr && valueOfGift==newValueOfGift ){
        return false;
    }return true;

}

bool repetitionCheck3(string eventName,int discountRate_2)
{
    if(eventName==eventNameStr && discountRate_2==newDiscountRate_2  ){
        return false;
    }return true;

}

//-------------------------------------------------------

bool discountCheck_1 (int numOfParks){
    if (numOfParks >= minPurchase){
        return true;
    }else{
        return false;
    }
}

bool discountCheck_2 (int validDay, int validMonth, int validYear){
    if (validDay == oldEventDay && validMonth == oldEventMonth && validYear == oldEventYear){
        return true;
    }else{
        return false;
    }
}

//1. ADD ADMIN LIST------------------------------------------------------------------------------------------------------

string usernameReset (vector <Admin>& newList){
    int looper = 0;
    do{

    system("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|                   Add Admin Account                   |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl;

    cout <<"\nEnter new username: ";
    getline(cin,username);

        if(!isPunct(username) && !isSpace(username)&& isLetters(username) && username.size()<15 && username.size()>3){

            if (usernameCheck(newList ,username)){
            return username;

            }else{
            cout<<"\nInvalid input.";
            cout<<"\nUsername already exists.\n";
            system("PAUSE");
            }

        }else{
        cout<<"\nInvalid input.";
        cout<<"\nNo spaces and punctuations are allowed.";
        cout<<"\nUsername must be between 3 and 15 characters.";
        cout<<"\nUsername must have at least 1 alphabet.\n";
        system("PAUSE");
        }

    }while (looper == 0);
}

string passwordReset (vector <Admin>& newList){
    int looper = 0;
    do{

    system("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|                   Add Admin Account                   |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl;

    cout <<"\nEnter new username: "<<username;

    cout << "\n\nEnter new password: ";
    getline(cin,password);

        if(!isPunct(password) && !isSpace(password)&& password.size()>4 && password.size()<11){
            return password;

        }else{
            cout<<"\nInvalid input.";
            cout<<"\nNo spaces and punctuations are allowed.";
            cout<<"\nPassword length must be between 4 and 11 characters.\n";
            system("PAUSE");
        }

    }while (looper == 0);
}

void fillList (vector <Admin>& newList){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    createdYear = 1900 + ltm->tm_year;
    createdMonth = 1 + ltm->tm_mon;
    createdDay = ltm->tm_mday;

    Admin newAdmin(username,password,createdDay,createdMonth,createdYear);
    newList.push_back(newAdmin);
    cout << endl<<endl;

}

//2. Display ADMIN list
void printList(const vector <Admin> & newList){
    system("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|                  Display Admin List                   |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl<<endl;

    unsigned int size1 = newList.size();
    cout<<" No. "<<setw(20)<<"Username"<<setw(30)<<"Created Date"<<endl;


    for (unsigned int i = 0 ; i < size1 ; i++){

        cout <<"  "<<i+1<<setw(20)<< newList[i].getUsername()<<setw(25)
        <<newList[i].getCreatedDay()<<"/"<<newList[i].getCreatedMonth()<<"/"<<newList[i].getCreatedYear()<<endl;
        cout << endl;
    }
}

//-----Purchase Date Calculator-----------------------------------------------------------------

int purchaseDateCal(){

   // current date/time based on current system
   time_t now = time(0);

   tm *ltm = localtime(&now);
   // various components of tm structure
   purchaseYear = 1900 + ltm->tm_year; //tm_year means years since 1900
   purchaseMonth = 1 + ltm->tm_mon; //tm_mon means months since January
   purchaseDay = ltm->tm_mday; //tm_mday means day of the month

   return purchaseDay,purchaseMonth,purchaseYear;
}

int currentDateCal(){

  time_t now = time(0);

   tm *ltm = localtime(&now);
   currentYear = 1900 + ltm->tm_year;
   currentMonth = 1 + ltm->tm_mon;
   currentDay = ltm->tm_mday;

   return currentDay,currentMonth,currentYear;
}
//3. add park

static int getParkID(char action){
    static int parkID = 4;
    if (action == '+'){
    return parkID++;

    }else {
    return parkID--;
    }
}

string parkNameReset(const vector <Park>& newParkList){
    int looper = 0;
    do{

    system("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|                       Add Park                        |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl;

        cout<<"\nEnter new park name: ";
        getline(cin,inputParkName);

        if(isLetters(inputParkName) && !isNumbers(inputParkName) && !isPunct(inputParkName) && inputParkName.size()>3 && inputParkName.size()<15){

            for (int i=0 ; i<inputParkName.length() ; i++){
                inputParkName[i] = toupper(inputParkName[i]);
            }

            if (repetitionParkNameCheck(newParkList,inputParkName)){

                parkName = inputParkName;
                return parkName;

            }else{
                cout<<"\nInvalid input."<<endl;
                cout<<"Park name already exists."<<endl;
                system("PAUSE");
            }

        }else{
            cout<<"\nInvalid input."<<endl;
            cout<<"Enter only letters."<<endl;
            cout<<"Park name must be between 3 and 15 characters."<<endl;
            system("PAUSE");
        }

    }while (looper == 0 );
}

//4. adjust ticket price
int childTicketPriceReset(){
    int looper = 0;
    do{

    system("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|                  Adjust Ticket Price                  |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl;

    cout<<"\nNote: Children (12 years old and below)"<<endl;
    cout<<"      Adults   (13 years old and above)"<<endl;
    cout<<"      Seniors  (60 years old and above)"<<endl;

    cout<<"\nCurrent Ticket Price (Children): RM"<<childTicketPrice<<endl;
    cout<<"                     (Adults)  : RM"<<adultTicketPrice<<endl;
    cout<<"                     (Seniors) : RM"<<seniorTicketPrice<<endl;

    cout<<"\nNew Ticket Price     (Children): RM";
    getline(cin,childTicketPriceStr);
        if (!isLetters(childTicketPriceStr) && isNumbers(childTicketPriceStr) && !isPunct(childTicketPriceStr) && !isSpace(childTicketPriceStr)){

                stringstream (childTicketPriceStr) >> newChildTicketPrice;
                    if(newChildTicketPrice >= 10 && newChildTicketPrice <= 9999){
                            return newChildTicketPrice;

                    }else
                        cout<<"\nInvalid input."<<endl;
                        cout<<"Ticket price must range from RM10 to RM9999."<<endl;
                        system("PAUSE");

        }else{
            cout<<"\nInvalid input."<<endl;
            cout<<"Enter only numbers."<<endl;
            system("PAUSE");
        }

    }while(looper == 0);
}

int adultTicketPriceReset(){
    int looper = 0;
    do{

    system("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|                  Adjust Ticket Price                  |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl;

    cout<<"\nNote: Children (12 years old and below)"<<endl;
    cout<<"      Adults   (13 years old and above)"<<endl;
    cout<<"      Seniors  (60 years old and above)"<<endl;

    cout<<"\nCurrent Ticket Price (Children): RM"<<childTicketPrice<<endl;
    cout<<"                     (Adults)  : RM"<<adultTicketPrice<<endl;
    cout<<"                     (Seniors) : RM"<<seniorTicketPrice<<endl;

    cout<<"\nNew Ticket Price     (Children): RM"<<childTicketPriceStr<<endl;

    cout<<"                     (Adults)  : RM";
    getline(cin,adultTicketPriceStr);
         if (!isLetters(adultTicketPriceStr) && isNumbers(adultTicketPriceStr) && !isPunct(adultTicketPriceStr) && !isSpace(adultTicketPriceStr)){

                stringstream (adultTicketPriceStr) >> newAdultTicketPrice;
                    if( newAdultTicketPrice >= 10 && newAdultTicketPrice <= 9999){
                            return newAdultTicketPrice;

                    }else
                        cout<<"\nInvalid input."<<endl;
                        cout<<"Ticket price must range from RM10 to RM9999."<<endl;
                        system("PAUSE");

        }else{
             cout<<"\nInvalid input."<<endl;
             cout<<"Enter only numbers."<<endl;
             system("PAUSE");
        }

    }while(looper == 0);
}

int seniorTicketPriceReset(){
    int looper = 0;
    do{

    system("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|                  Adjust Ticket Price                  |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl;

    cout<<"\nNote: Children (12 years old and below)"<<endl;
    cout<<"      Adults   (13 years old and above)"<<endl;
    cout<<"      Seniors  (60 years old and above)"<<endl;

    cout<<"\nCurrent Ticket Price (Children): RM"<<childTicketPrice<<endl;
    cout<<"                     (Adults)  : RM"<<adultTicketPrice<<endl;
    cout<<"                     (Seniors) : RM"<<seniorTicketPrice<<endl;

    cout<<"\nNew Ticket Price     (Children): RM"<<childTicketPriceStr<<endl;
    cout<<"                     (Adults)  : RM"<<adultTicketPriceStr<<endl;

    cout<<"                     (Seniors) : RM";
    getline(cin,seniorTicketPriceStr);
        if (!isLetters(seniorTicketPriceStr) && isNumbers(seniorTicketPriceStr) && !isPunct(seniorTicketPriceStr) && !isSpace(seniorTicketPriceStr)){

                stringstream (seniorTicketPriceStr) >> newSeniorTicketPrice;
                    if( newSeniorTicketPrice >= 10 && newSeniorTicketPrice <= 9999){
                            return newSeniorTicketPrice;

                    }else
                        cout<<"\nInvalid input."<<endl;
                        cout<<"Ticket price must range from RM10 to RM9999."<<endl;
                        system("PAUSE");

        }else{
            cout<<"\nInvalid input."<<endl;
            cout<<"Enter only numbers."<<endl;
            system("PAUSE");
        }

    }while (looper == 0);
}

//---Reset 1------------------------------------------------------------------------------------
int minPurchaseReset(){

    int looper = 0;
    do{
    system("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|               Adjust Promotions & Gifts               |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl<<endl;

    cout<<"Current Promotions & Gifts:                    "<<endl;
    cout<<"Buy tickets with access to "<<minPurchase<<" parks at once"<<endl;
    cout<<"for "<<discountRate_1<<"% off."<<endl;

    cout<<"\nCurrent Min Park Purchase: "<<minPurchase;
    cout<<"\nNew Min Park Purchase    : ";
    getline(cin,minPurchaseStr);

        if(!isLetters(minPurchaseStr) && isNumbers(minPurchaseStr) && !isPunct(minPurchaseStr) && !isSpace(minPurchaseStr)){

           stringstream(minPurchaseStr)>>newMinPurchase;

           if (newMinPurchase >= 1 && newMinPurchase <= 3){
                return newMinPurchase;

           }else{

                cout<<"\nInvalid input."<<endl;
                cout<<"Minimum park purchase must range from 1 to 3."<<endl;
                system("PAUSE");
           }

        }else{

            cout<<"\nInvalid input."<<endl;
            cout<<"Enter only numbers."<<endl;
            system("PAUSE");

        }}while(looper==0);
}

int discountRateReset(){

    int looper = 0;
    discountRateResetMain:
    do{
    system("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|               Adjust Promotions & Gifts               |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl<<endl;

    cout<<"Current Promotions & Gifts:                    "<<endl;
    cout<<"Buy tickets with access to "<<minPurchase<<" parks at once"<<endl;
    cout<<"for "<<discountRate_1<<"% off."<<endl;

    cout<<"\nCurrent Min Park Purchase: "<<minPurchase;
    cout<<"\nNew Min Park Purchase    : "<<newMinPurchase;

    cout<<"\n\nCurrent Discount value: "<<discountRate_1;
    cout<<"\nNew Discount value (%): ";
    getline(cin,discountRateStr);

        if(!isLetters( discountRateStr) && isNumbers( discountRateStr) && !isPunct( discountRateStr) && !isSpace( discountRateStr)){

            stringstream(discountRateStr) >> newDiscountRate_1;


            if( newDiscountRate_1 <= 0 || newDiscountRate_1 > 100 ){

                cout<<"\nInvalid input."<<endl;
                cout<<"Discount value must range from 1 to 100."<<endl;
                system("PAUSE");
                goto discountRateResetMain;

            }else{
                 return newDiscountRate_1;
                 }

         }else{
            cout<<"\nInvalid input."<<endl;
            cout<<"Enter only numbers."<<endl;
            system("PAUSE");
            goto discountRateResetMain;
    }

    }while(looper == 0);


}
//-Reset 2-----------------------------------------------------------------------------------------------------------------
int ticketPriceReset(){
    int looper = 0;
    do{
    system("cls");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|               Adjust Promotions & Gifts               |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl<<endl;

    cout<<"Current Promotions & Gifts:                    "<<endl;
    cout<<"Purchase tickets over RM"<<minTotalPrice<<" to get up "<<endl;
    cout<<"to RM"<<valueOfGift<<" worth of "<<typeOfGift<<" voucher."<<endl;

    cout<<"\nCurrent Total Ticket Price: RM"<<minTotalPrice;
    cout<<"\nNew Total Ticket Price    : RM";
    getline(cin,minTotalPriceStr);

    if(!isLetters(minTotalPriceStr) && isNumbers(minTotalPriceStr) && !isPunct(minTotalPriceStr) && !isSpace(minTotalPriceStr)){

        stringstream(minTotalPriceStr)>> newMinTotalPrice;

        if (newMinTotalPrice >= 10 && newMinTotalPrice <= 9999 ){
            return newMinTotalPrice;

        }else{
            cout<<"\nInvalid input."<<endl;
            cout<<"New total ticket price must range from RM10 to RM9999."<<endl;
            system("PAUSE");
        }

    }else{

        cout<<"\nInvalid input."<<endl;
        cout<<"Enter only numbers."<<endl;
        system("PAUSE");
    }

    }while (looper==0);
}

string giftReset(){
    int looper = 0;
    do{
    system("cls");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|               Adjust Promotions & Gifts               |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl<<endl;

    cout<<"Current Promotions & Gifts:                    "<<endl;
    cout<<"Purchase tickets over RM"<<minTotalPrice<<" to get up "<<endl;
    cout<<"to RM"<<valueOfGift<<" worth of "<<typeOfGift<<" voucher."<<endl;

    cout<<"\nCurrent Total Ticket Price: RM"<<minTotalPrice;
    cout<<"\nNew Total Ticket Price    : RM"<<newMinTotalPrice;

    cout<<"\n\nCurrent Type of Voucher        : "<<typeOfGift;
    cout<<"\nNew Type of Voucher (FOOD/GIFT): ";
    getline(cin,typeOfGiftStr);

    for (int i=0 ; i<typeOfGiftStr.length() ; i++){
        typeOfGiftStr[i] = toupper(typeOfGiftStr[i]);
    }

    if ( typeOfGiftStr != "FOOD" && typeOfGiftStr != "GIFT"){

        cout<<"\nInvalid input."<<endl;
        cout<<"Enter only either 'FOOD' or 'GIFT'."<<endl;
        system ("PAUSE");

        }else{

        return typeOfGiftStr;

        }
    }while (looper==0);
}

int giftValueReset(){

    int looper = 0;
    giftValueMain:
    do{
    system("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|               Adjust Promotions & Gifts               |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl<<endl;

    cout<<"Current Promotions & Gifts:                    "<<endl;
    cout<<"Purchase tickets over RM"<<minTotalPrice<<" to get up "<<endl;
    cout<<"to RM"<<valueOfGift<<" worth of "<<typeOfGift<<" voucher."<<endl;


    cout<<"\nCurrent Total Ticket Price: RM"<<minTotalPrice;
    cout<<"\nNew Total Ticket Price    : RM"<<newMinTotalPrice;

    cout<<"\n\nCurrent Type of Voucher        : "<<typeOfGift;
    cout<<"\nNew Type of Voucher (FOOD/GIFT): "<<typeOfGiftStr;

    cout<<"\n\nCurrent Voucher Value: RM"<<valueOfGift;
    cout<<"\nNew Voucher Value    : RM";
    getline(cin,valueOfGiftStr);

   if(!isLetters(valueOfGiftStr) && isNumbers(valueOfGiftStr) && !isPunct(valueOfGiftStr) && !isSpace(valueOfGiftStr)){

      stringstream(valueOfGiftStr)>> newValueOfGift;

        if (newValueOfGift >= 10 && newValueOfGift <= 9999 ){

        return newValueOfGift;

        }else{
        cout<<"\nInvalid input."<<endl;
        cout<<"New voucher value must range from RM10 to RM9999."<<endl;
        system("PAUSE");
        goto giftValueMain;

        }

    }else{

        cout<<"\nInvalid input."<<endl;
        cout<<"Enter only numbers."<<endl;
        system("PAUSE");
        goto giftValueMain;

    }

    return newMinTotalPrice,typeOfGiftStr,newValueOfGift;

    }while (looper == 0);
}

//-Reset 3----------------------------------------------------------------------------------------------------------
string eventNameReset(){

int looper = 0;

do{
    system ("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|               Adjust Promotions & Gifts               |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl<<endl;

    cout<<"Current Promotions & Gifts:                    "<<endl;
    cout<<"Upcoming discount - "<<eventName<<"    "<<endl;
    cout<<"- All tickets "<<discountRate_2<<"% off on "<<oldEventDay<<"/"<<oldEventMonth<<"/"<<oldEventYear<<"!"<<endl;

    cout<<"\nCurrent Event Name: "<<eventName;
    cout<<"\nNew Event Name    : ";
    getline(cin,eventNameStr);

    for (int i=0 ; i<eventNameStr.length() ; i++){
        eventNameStr[i] = toupper(eventNameStr[i]);
    }

    if(isLetters(eventNameStr)){

        return eventNameStr;

    }else{

        cout<<"\nInvalid input."<<endl;
        cout<<"Event name must have alphabets."<<endl;
        system("PAUSE");

    }}while(looper == 0);

}

int discountRate2Reset(){

int looper = 0;
discountRate2ResetMain:
do{
    system("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|               Adjust Promotions & Gifts               |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl<<endl;

    cout<<"Current Promotions & Gifts:                    "<<endl;
    cout<<"Upcoming discount - "<<eventName<<"    "<<endl;
    cout<<"- All tickets "<<discountRate_2<<"% off on "<<oldEventDay<<"/"<<oldEventMonth<<"/"<<oldEventYear<<"!"<<endl;

    cout<<"\nCurrent Event Name: "<<eventName;
    cout<<"\nNew Event Name    : "<<eventNameStr;

    cout<<"\n\nCurrent Discount Value: "<<discountRate_2;
    cout<<"\nNew Discount Value (%): ";
    getline (cin,discountRate2Str);

   if(!isLetters(discountRate2Str) && isNumbers(discountRate2Str) && !isPunct(discountRate2Str) && !isSpace(discountRate2Str)){
        stringstream(discountRate2Str) >> newDiscountRate_2 ;

            if( newDiscountRate_2 <= 0 || newDiscountRate_2 > 100 ){

                cout<<"\nInvalid input."<<endl;
                cout<<"New discount value must range from 1 to 100."<<endl;
                system("PAUSE");
                goto discountRate2ResetMain;


                }else{
                return newDiscountRate_2;
                    }


        }else{
            cout<<"\nInvalid input."<<endl;
            cout<<"Enter only numbers."<<endl;
            system("PAUSE");
            goto discountRate2ResetMain;
            }


    }while(looper == 0);


}

int eventDateReset(){

int looper = 0;

resetEvent:
do{
     system ("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|               Adjust Promotions & Gifts               |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl<<endl;

    cout<<"Current Promotions & Gifts:                    "<<endl;
    cout<<"Upcoming discount - "<<eventName<<"    "<<endl;
    cout<<"- All tickets "<<discountRate_2<<"% off on "<<oldEventDay<<"/"<<oldEventMonth<<"/"<<oldEventYear<<"!"<<endl;

    cout<<"\nCurrent Event Name: "<<eventName;
    cout<<"\nNew Event Name    : "<<eventNameStr;

    cout<<"\n\nCurrent Discount Value: "<<discountRate_2;
    cout<<"\nNew Discount Value (%): "<<newDiscountRate_2;

    cout<<"\n\nCurrent Date Eligible        : "<<oldEventDay<<"/"<<oldEventMonth<<"/"<<oldEventYear ;
    cout<<"\nNew Date Eligible- Day   (DD): ";
    getline (cin,eventDayStr);
    cout<<"\n                - Month  (MM): ";
    getline (cin,eventMonthStr);
    cout<<"\n                - Year (YYYY): ";
    getline (cin,eventYearStr);

     if (!isLetters(eventDayStr)   && isNumbers(eventDayStr)   && !isPunct(eventDayStr)   && !isSpace(eventDayStr)   &&
         !isLetters(eventMonthStr) && isNumbers(eventMonthStr) && !isPunct(eventMonthStr) && !isSpace(eventMonthStr) &&
         !isLetters(eventYearStr)  && isNumbers(eventYearStr)  && !isPunct(eventYearStr)  && !isSpace(eventYearStr)  ){

                            stringstream (eventDayStr) >> eventDay;
                            stringstream (eventMonthStr) >> eventMonth;
                            stringstream (eventYearStr) >> eventYear;


                        if (eventDay >= 1 && eventDay <= 31 && eventMonth >= 1 && eventMonth <= 12 && eventYear >= 1000 && eventYear <= 9999){


                        if ((eventDay == 31) && (eventMonth == 4 || eventMonth == 6 || eventMonth == 9 || eventMonth == 11)){

                            string monthName;

                                    if (eventMonth == 4){
                                        monthName = "April";
                                    }else if(eventMonth == 6){
                                        monthName = "June";
                                    }else if(eventMonth == 9){
                                        monthName = "September";
                                    }else{ //eventMonth == 11
                                        monthName = "November";
                                    }

                            cout << "\nInvalid input."<<endl;
                            cout << "There's no 31st in "<<monthName<<".\n"<<endl;
                            system("PAUSE");
                            goto resetEvent;
                        }

                        int x = eventYear%4;

                        if ( (x != 0) && (eventDay >= 29 && eventMonth == 2)){

                            cout << "\nInvalid input."<<endl;
                            cout << "There's no 29th or above in February "<<eventYear<<".\n"<<endl;
                            system("PAUSE");
                            goto resetEvent;

                        }

                        if (eventDay > 29 && eventMonth == 2){

                            cout << "\nInvalid input."<<endl;
                            cout << "There's no 30th and 31st in February.\n"<<endl;
                            system("PAUSE");
                            goto resetEvent;
                        }

                            currentDateCal();

                        if ( eventYear > currentYear ){

                            return eventDay,eventMonth,eventYear;

                        }else if ( eventYear ==  currentYear ){

                                    if ( eventMonth >  currentMonth ){

                                       return eventDay,eventMonth,eventYear;

                                    }else if ( eventMonth ==  currentMonth ){

                                                if ( eventDay >=  currentDay ){

                                                   return eventDay,eventMonth,eventYear;

                        }else{
                            cout << "\nInvalid input."<<endl;
                            cout << "Date must be valid for today or later.\n"<<endl;
                            system("PAUSE");
                        }

                        }else{
                            cout << "\nInvalid input."<<endl;
                            cout << "Date must be valid for today or later.\n"<<endl;
                            system("PAUSE");
                        }

                        }else{
                            cout << "\nInvalid input."<<endl;
                            cout << "Date must be valid for today or later.\n"<<endl;
                            system("PAUSE");
                        }

                        }else{
                            cout << "\nInvalid input."<<endl;
                            cout << "Enter a proper date without spaces with the format of: "<<endl;
                            cout << "Day  : DD"<<endl;
                            cout << "Month: MM"<<endl;
                            cout << "Year : YYYY\n"<<endl;
                            system("PAUSE");
                        }

                        }else{
                            cout << "\nInvalid input."<<endl;
                            cout << "Enter a proper date without spaces with the format of: "<<endl;
                            cout << "Day  : DD"<<endl;
                            cout << "Month: MM"<<endl;
                            cout << "Year : YYYY\n"<<endl;
                            system("PAUSE");
                        }
   }while(looper == 0 );
}

//-----List of parks and ticket prices display function-----------------------------------------------------------

void fillPark ( vector <Park>& newParkList){
    Park newPark (parkName,parkID);
    newParkList.push_back(newPark);
    cout<<endl;

}

void printPark (const vector <Park>& newParkList){
            parkListReset:
            system("CLS");
            cout<<"+---------------------------------------------+"<<endl;
            cout<<"|                                             |"<<endl;
            cout<<"|          Park List & Ticket Prices          |"<<endl;
            cout<<"|                                             |"<<endl;
            cout<<"+---------------------------------------------+"<<endl<<endl;

            cout<<"+---------------------------------------------+"<<endl;
            cout<<"                                               "<<endl;
            cout<<"       No     Park ID     Park Name            "<<endl;

            for (unsigned int i=0 ; i<newParkList.size() ; i++){
                cout<<"       "<<newParkList[i].getParkID()<<".     TP"<<newParkList[i].getParkID()<<"         "<<newParkList[i].getParkName()<<endl;
            }
            cout<<"\n+---------------------------------------------+"<<endl<<endl;

            cout<<"+---------------------------------------------+"<<endl;
            cout<<"                                               "<<endl;
            cout<<"       Ticket Type                Price        "<<endl;
            cout<<"       Children                   RM"<<childTicketPrice<<endl;
            cout<<"       (12 years old and below)                "<<endl;
            cout<<"                                               "<<endl;
            cout<<"       Adults                     RM"<<adultTicketPrice<<endl;
            cout<<"       (13 years old and above)                "<<endl;
            cout<<"                                               "<<endl;
            cout<<"       Seniors                    RM"<<seniorTicketPrice<<endl;
            cout<<"       (60 years old and above)                "<<endl;
            cout<<"                                               "<<endl;
            cout<<"                                               "<<endl;
            cout<<"       Add on                     Price        "<<endl;
            cout<<"       Express pass               RM50         "<<endl;
            cout<<"                                               "<<endl;
            cout<<"+---------------------------------------------+"<<endl;

                cout<<"\nEnter '0' to go back to guest menu."<<endl;
                getline(cin,anyKey);

                    if (anyKey != "0"){
                        cout<<"\nInvalid input."<<endl;
                        cout<<"Enter only '0' to go back to guest menu."<<endl;
                        system("PAUSE");
                        goto parkListReset;

                    }else{
                        return;

                    }
}

//-----Ticketing Reset-------------------------------------------------------------------------

int numOfParksReset (const vector <Park>& newParkList){
                    int looper = 0;
                    do {
                    system("CLS");
                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"|                  Ticketing                  |"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"+---------------------------------------------+"<<endl;

                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"                                               "<<endl;
                    cout<<"       No     Park ID     Park Name            "<<endl;
                    for (unsigned int i=0 ; i<newParkList.size() ; i++){
                    cout<<"       "<<i+1<<".     TP"<<newParkList[i].getParkID()<<"         "<<newParkList[i].getParkName()<<endl;
                    }
                    cout<<"\n+---------------------------------------------+"<<endl;

                    cout << "\nEnter number of parks to be purchased (max 3): ";
                    getline(cin,numOfParksStr);

                        if(!isLetters(numOfParksStr) && isNumbers(numOfParksStr) && !isPunct(numOfParksStr) && !isSpace(numOfParksStr)){

                            stringstream (numOfParksStr) >> numOfParks;

                            if (numOfParks <= 3 && numOfParks > 0){
                                return numOfParks;

                            }else if(numOfParks == 0){
                                    cout<<"\nInvalid input."<<endl;
                                    cout<<"Please enter number of parks at least 1."<<endl;
                                    system("PAUSE");

                            }else{
                                    cout<<"\nInvalid input."<<endl;
                                    cout<<"Exceeds maximum number of parks that can be purchased."<<endl;
                                    cout<<"Please enter number of parks less or equal to 3."<<endl;
                                    system("PAUSE");
                            }

                        }else{
                            cout<<"\nInvalid input."<<endl;
                            cout<<"Enter only numbers."<<endl;
                            system("PAUSE");
                        }

                    }while(looper == 0);
}

int parkIDReset1 (const vector <Park>& newParkList, vector <int>& newParkIDList){
                    int looper1 = 0;
                    int looper2 = 0;
                    do {
                    parkIDResetMain:
                    system("CLS");
                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"|                  Ticketing                  |"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"+---------------------------------------------+"<<endl;

                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"                                               "<<endl;
                    cout<<"       No     Park ID     Park Name            "<<endl;
                    for (unsigned int i=0 ; i<newParkList.size() ; i++){
                    cout<<"       "<<i+1<<".     TP"<<newParkList[i].getParkID()<<"         "<<newParkList[i].getParkName()<<endl;
                    }
                    cout<<"\n+---------------------------------------------+"<<endl;

                    cout << "\nEnter number of parks to be purchased (max 3): "<<numOfParks<<endl;

                    cout<<"\nEnter Park ID: TP";
                    getline(cin,parkIDStr);

                        if (!isLetters(parkIDStr) && isNumbers(parkIDStr) && !isPunct(parkIDStr) && !isSpace(parkIDStr)){

                            stringstream (parkIDStr) >> parkID;

                        while (looper2 == 0){
                            if (parkIDCheck(newParkList,parkID)){

                                newParkIDList.push_back(parkID);
                                looper2 = 1;

                            }else{
                            cout<<"\nInvalid park ID."<<endl;
                            system("PAUSE");
                            goto parkIDResetMain;
                            }
                        }

                        }else{
                        cout<<"\nInvalid input."<<endl;
                        cout<<"Enter only numbers."<<endl;
                        system("PAUSE");
                        goto parkIDResetMain;
                        }

                    return parkID;

                    }while(looper1 == 0);
}

int parkIDReset2 (const vector <Park>& newParkList, vector <int>& newParkIDList){
                    int looper1 = 0;
                    int looper2 = 0;
                    do {
                    parkIDResetMain:
                    system("CLS");
                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"|                  Ticketing                  |"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"+---------------------------------------------+"<<endl;

                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"                                               "<<endl;
                    cout<<"       No     Park ID     Park Name            "<<endl;
                    for (unsigned int i=0 ; i<newParkList.size() ; i++){
                    cout<<"       "<<i+1<<".     TP"<<newParkList[i].getParkID()<<"         "<<newParkList[i].getParkName()<<endl;
                    }
                    cout<<"\n+---------------------------------------------+"<<endl;

                    cout << "\nEnter number of parks to be purchased (max 3): "<<numOfParks<<endl;

                    cout<<"\nEnter Park ID: TP"<<newParkIDList[0]<<endl;

                    cout<<"\nEnter Park ID: TP";
                    getline(cin,parkIDStr);

                        if (!isLetters(parkIDStr) && isNumbers(parkIDStr) && !isPunct(parkIDStr) && !isSpace(parkIDStr)){

                            stringstream (parkIDStr) >> parkID;

                        while (looper2 == 0){
                            if (parkIDCheck(newParkList,parkID)){

                                    if (repetitionParkIDCheck (newParkIDList,parkID)){

                                    newParkIDList.push_back(parkID);
                                    looper2 = 1;

                                    }else{
                                        cout<<"\nInvalid input."<<endl;
                                        cout<<"Repeated park ID."<<endl;
                                        system("PAUSE");
                                        goto parkIDResetMain;
                                    }

                            }else{
                            cout<<"\nInvalid park ID."<<endl;
                            system("PAUSE");
                            goto parkIDResetMain;
                            }
                        }

                        }else{
                        cout<<"\nInvalid input."<<endl;
                        cout<<"Enter only numbers."<<endl;
                        system("PAUSE");
                        goto parkIDResetMain;
                        }

                    return parkID;

                    }while(looper1 == 0);
}

int parkIDReset3 (const vector <Park>& newParkList, vector <int>& newParkIDList){
                    int looper1 = 0;
                    int looper2 = 0;
                    do {
                    parkIDResetMain:
                    system("CLS");
                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"|                  Ticketing                  |"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"+---------------------------------------------+"<<endl;

                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"                                               "<<endl;
                    cout<<"       No     Park ID     Park Name            "<<endl;
                    for (unsigned int i=0 ; i<newParkList.size() ; i++){
                    cout<<"       "<<i+1<<".     TP"<<newParkList[i].getParkID()<<"         "<<newParkList[i].getParkName()<<endl;
                    }
                    cout<<"\n+---------------------------------------------+"<<endl;

                    cout << "\nEnter number of parks to be purchased (max 3): "<<numOfParks<<endl;

                    cout<<"\nEnter Park ID: TP"<<newParkIDList[0]<<endl;

                    cout<<"\nEnter Park ID: TP"<<newParkIDList[1]<<endl;

                    cout<<"\nEnter Park ID: TP";
                    getline(cin,parkIDStr);

                        if (!isLetters(parkIDStr) && isNumbers(parkIDStr) && !isPunct(parkIDStr) && !isSpace(parkIDStr)){

                            stringstream (parkIDStr) >> parkID;

                        while (looper2 == 0){
                            if (parkIDCheck(newParkList,parkID)){

                                     if (repetitionParkIDCheck (newParkIDList,parkID)){

                                    newParkIDList.push_back(parkID);
                                    looper2 = 1;

                                    }else{
                                    cout<<"\nInvalid input."<<endl;
                                    cout<<"Repeated park ID."<<endl;
                                    system("PAUSE");
                                    goto parkIDResetMain;
                                    }

                            }else{
                            cout<<"\nInvalid park ID."<<endl;
                            system("PAUSE");
                            goto parkIDResetMain;
                            }
                        }

                        }else{
                        cout<<"\nInvalid input."<<endl;
                        cout<<"Enter only numbers."<<endl;
                        system("PAUSE");
                        goto parkIDResetMain;
                        }

                    return parkID;

                    }while(looper1 == 0);
}

string validOfExPReset(const vector <Park>& newParkList, vector <int>& newParkIDList){
                do{
                    system("CLS");
                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"|                  Ticketing                  |"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"+---------------------------------------------+"<<endl;

                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"                                               "<<endl;
                    cout<<"       No     Park ID     Park Name            "<<endl;
                    for (unsigned int i=0 ; i<newParkList.size() ; i++){
                    cout<<"       "<<i+1<<".     TP"<<newParkList[i].getParkID()<<"         "<<newParkList[i].getParkName()<<endl;
                    }
                    cout<<"\n+---------------------------------------------+"<<endl;

                    cout << "\nEnter number of parks to be purchased (max 3): "<<numOfParks<<endl;

                    for (unsigned int i = 0 ; i < numOfParks ; i++){
                    cout << "\nEnter Park ID: TP"<<newParkIDList[i]<<endl;
                    }

                    cout << "\nExpress pass (Y/N): ";
                    getline(cin,validOfExP);

                        if (validOfExP == "Y" || validOfExP == "N" ||
                            validOfExP == "y" || validOfExP == "n" ){

                            return validOfExP;

                        }else{
                            cout << "\nInvalid input."<<endl;
                            cout << "Enter only letter 'Y' for yes and letter 'N' for no."<<endl;
                            cout << "No spaces are allowed."<<endl;
                            system("PAUSE");
                        }
                }while(validOfExP != "Y" && validOfExP != "y" && validOfExP != "N" && validOfExP != "n");
}

int validDateReset(const vector <Park>& newParkList, vector <int>& newParkIDList){
                    int looper = 0;
                    reset:
                    do {
                    system("CLS");
                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"|                  Ticketing                  |"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"+---------------------------------------------+"<<endl;

                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"                                               "<<endl;
                    cout<<"       No     Park ID     Park Name            "<<endl;
                    for (unsigned int i=0 ; i<newParkList.size() ; i++){
                    cout<<"       "<<i+1<<".     TP"<<newParkList[i].getParkID()<<"         "<<newParkList[i].getParkName()<<endl;
                    }
                    cout<<"\n+---------------------------------------------+"<<endl;

                    cout << "\nEnter number of parks to be purchased (max 3): "<<numOfParks<<endl;

                    for (unsigned int i = 0 ; i < numOfParks ; i++){
                        cout << "\nEnter Park ID: TP"<<newParkIDList[i]<<endl;
                    }

                    cout << "\nExpress pass (Y/N): "<<validOfExP<<endl;

                    cout << "\nDate - Day    (DD): ";
                    getline(cin,validDayStr);

                    cout << "     - Month  (MM): ";
                    getline(cin,validMonthStr);

                    cout << "     - Year (YYYY): ";
                    getline(cin,validYearStr);

                        if (!isLetters(validDayStr)   && isNumbers(validDayStr)   && !isPunct(validDayStr)   && !isSpace(validDayStr)   &&
                            !isLetters(validMonthStr) && isNumbers(validMonthStr) && !isPunct(validMonthStr) && !isSpace(validMonthStr) &&
                            !isLetters(validYearStr)  && isNumbers(validYearStr)  && !isPunct(validYearStr)  && !isSpace(validYearStr)  ){

                            stringstream (validDayStr) >> validDay; //Converting String to Int
                            stringstream (validMonthStr) >> validMonth;
                            stringstream (validYearStr) >> validYear;

                        if (validDay >= 1 && validDay <= 31 && validMonth >= 1 && validMonth <= 12 && validYear >= 1000 && validYear <= 9999){


                        if ((validDay == 31) && (validMonth == 4 || validMonth == 6 || validMonth == 9 || validMonth == 11)){

                            string monthName;

                                    if (validMonth == 4){
                                        monthName = "April";
                                    }else if(validMonth == 6){
                                        monthName = "June";
                                    }else if(validMonth == 9){
                                        monthName = "September";
                                    }else{ //validMonth == 11
                                        monthName = "November";
                                    }

                            cout << "\nInvalid input."<<endl;
                            cout << "There's no 31st in "<<monthName<<"."<<endl;
                            system("PAUSE");
                            goto reset;
                        }

                        int x = validYear%4;

                        if ( (x != 0) && (validDay >= 29 && validMonth == 2)){

                            cout << "\nInvalid input."<<endl;
                            cout << "There's no 29th or above in February "<<validYear<<"."<<endl;
                            system("PAUSE");
                            goto reset;
                        }

                        if (validDay > 29 && validMonth == 2){

                            cout << "\nInvalid input."<<endl;
                            cout << "There's no 30th and 31st in February."<<endl;
                            system("PAUSE");
                            goto reset;
                        }

                            purchaseDateCal();

                        if ( validYear > purchaseYear ){

                            return validDay,validMonth,validYear;

                        }else if ( validYear == purchaseYear ){

                                    if ( validMonth > purchaseMonth ){

                                        return validDay,validMonth,validYear;

                                    }else if ( validMonth == purchaseMonth ){

                                                if ( validDay >= purchaseDay ){

                                                    return validDay,validMonth,validYear;

                        }else{ /* validDay < purchaseDay*/
                            cout << "\nInvalid input."<<endl;
                            cout << "Your ticket must be valid for today or later."<<endl;
                            system("PAUSE");
                        }

                        }else{ /* validMonth < purchaseMonth */
                            cout << "\nInvalid input."<<endl;
                            cout << "Your ticket must be valid for today or later."<<endl;
                            system("PAUSE");
                        }

                        }else{ /* validYear < purchaseYear */
                            cout << "\nInvalid input."<<endl;
                            cout << "Your ticket must be valid for today or later."<<endl;
                            system("PAUSE");
                        }

                        }else{
                            cout << "\nInvalid input."<<endl;
                            cout << "Enter a proper date without spaces with the format of: "<<endl;
                            cout << "Day  : DD"<<endl;
                            cout << "Month: MM"<<endl;
                            cout << "Year : YYYY"<<endl;
                            system("PAUSE");
                        }

                        }else{
                            cout << "\nInvalid input."<<endl;
                            cout << "Enter a proper date without spaces with the format of: "<<endl;
                            cout << "Day  : DD"<<endl;
                            cout << "Month: MM"<<endl;
                            cout << "Year : YYYY"<<endl;
                            system("PAUSE");
                        }
                    }while(looper == 0);
}

int numOfTicketsReset(const vector <Park>& newParkList, vector <int>& newParkIDList){
                    int looper = 0;
                    do {
                    system("CLS");
                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"|                  Ticketing                  |"<<endl;
                    cout<<"|                                             |"<<endl;
                    cout<<"+---------------------------------------------+"<<endl;

                    cout<<"+---------------------------------------------+"<<endl;
                    cout<<"                                               "<<endl;
                    cout<<"       No     Park ID     Park Name            "<<endl;
                    for (unsigned int i=0 ; i<newParkList.size() ; i++){
                    cout<<"       "<<i+1<<".     TP"<<newParkList[i].getParkID()<<"         "<<newParkList[i].getParkName()<<endl;
                    }
                    cout<<"\n+---------------------------------------------+"<<endl;

                    cout << "\nEnter number of parks to be purchased (max 3): "<<numOfParks<<endl;

                    for (unsigned int i = 0 ; i < numOfParks ; i++){
                    cout << "\nEnter Park ID: TP"<<newParkIDList[i]<<endl;
                    }

                    cout << "\nExpress pass (Y/N): "<<validOfExP<<endl;

                    cout << "\nDate - Day    (DD): "<<validDay<<endl;

                    cout << "     - Month  (MM): "<<validMonth<<endl;

                    cout << "     - Year (YYYY): "<<validYear<<endl;

                    cout << "\nNumber of tickets- Children ( RM"<<childTicketPrice<<" / person ) : ";
                    getline(cin,numChildrenStr);

                    cout << "                 - Adults   ( RM"<<adultTicketPrice<<" / person ): ";
                    getline(cin,numAdultsStr);

                    cout << "                 - Seniors  ( RM"<<seniorTicketPrice<<" / person ) : ";
                    getline(cin,numSeniorsStr);

                        if (!isLetters(numChildrenStr)   && isNumbers(numChildrenStr)   && !isPunct(numChildrenStr)   && !isSpace(numChildrenStr)   &&
                            !isLetters(numAdultsStr)     && isNumbers(numAdultsStr)     && !isPunct(numAdultsStr)     && !isSpace(numAdultsStr)     &&
                            !isLetters(numSeniorsStr)    && isNumbers(numSeniorsStr)    && !isPunct(numSeniorsStr)    && !isSpace(numSeniorsStr)    ){

                                stringstream (numChildrenStr) >> numChildren; //Converting String to Int
                                stringstream (numAdultsStr) >> numAdults;
                                stringstream (numSeniorsStr) >> numSeniors;

                        if (numChildren != 0 || numAdults != 0 || numSeniors != 0){

                                if (numChildren <= 100 && numAdults <= 100 && numSeniors <= 100){

                                    return numChildren,numAdults,numSeniors;

                                }else{
                                    cout << "\nInvalid input."<<endl;
                                    cout << "Maximum purchase of 100 tickets each category."<<endl;
                                    system("PAUSE");
                                }

                        }else{
                            cout << "\nInvalid input."<<endl;
                            cout << "Minimum purchase of at least 1 ticket."<<endl;
                            system("PAUSE");
                        }

                        }else{
                            cout << "\nInvalid input."<<endl;
                            cout << "Enter a number for each category without spacing."<<endl;
                            system("PAUSE");
                        }
                    }while(looper == 0);
}

//-----Payment1 Calculator-----------------------------------------------------------------------

int priceOfExPCal(){
                    if (validOfExP == "Yes"){
                        priceOfExP = 50;
                    }else{
                        /* validOfExP == "No" || validOfExP == "no" */
                        priceOfExP = 0;
                    }
                    return priceOfExP;
}

int numTicketsCal(){
    numTickets = numChildren + numAdults + numSeniors;
    return numTickets;
}

int discountCal(){
                    if ( discountCheck_1(numOfParks) && discountCheck_2(validDay, validMonth, validYear) ){
                        discount = discountRate_1 + discountRate_2;
                            if(discount>100){
                                discount=100;
                            }
                    }else if ( discountCheck_1(numOfParks) && !discountCheck_2(validDay, validMonth, validYear) ){
                        discount = discountRate_1;
                    }else if ( !discountCheck_1(numOfParks) && discountCheck_2(validDay, validMonth, validYear) ){
                        discount = discountRate_2;
                    }else{
                        discount = 0;
                    }
                    return discount;
}

string giftsCal(){
                    if ( totalPrice >= minTotalPrice){
                        stringstream giftsOutput;
                        giftsOutput <<"Free RM"<<valueOfGift<<" "<<typeOfGift<<" Voucher";
                        gifts = giftsOutput.str();
                    }else{
                        gifts = "-";
                    }
                    return gifts;
}

//-----Payment2 Reset-----------------------------------------------------------------------

string typesOfCardReset(){
                    do {
                    system("CLS");
                    cout<<"+---------------------------------------+"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"|                Payment                |"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"+---------------------------------------+"<<endl;
                    cout << "\nTypes of card (CREDIT/DEBIT): ";
                    getline(cin,typesOfCard);

                    for (int i=0 ; i<typesOfCard.length() ; i++){
                        typesOfCard[i] = toupper(typesOfCard[i]);
                    }

                        if (typesOfCard == "CREDIT" || typesOfCard == "DEBIT"){

                            return typesOfCard;

                        }else{
                            cout << "\nInvalid input." <<endl;
                            cout << "Enter only either CREDIT or DEBIT." <<endl;
                            system("PAUSE");
                        }
                    }while(typesOfCard != "CREDIT" && typesOfCard != "DEBIT" && typesOfCard != "credit" && typesOfCard != "debit");
}

string nameOfCardReset(){
                    int looper = 0;
                    do {
                    system("CLS");
                    cout<<"+---------------------------------------+"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"|                Payment                |"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"+---------------------------------------+"<<endl;
                    cout << "\nTypes of card (CREDIT/DEBIT): "<<typesOfCard<<endl;

                    cout << "\nName on card: ";
                    getline(cin,nameOfCard);

                        if (isLetters(nameOfCard) && !isNumbers(nameOfCard) && !isPunct(nameOfCard)){

                        for (int i=0 ; i<nameOfCard.length() ; i++){
                            nameOfCard[i] = toupper(nameOfCard[i]);
                        }

                                return nameOfCard;

                        }else{
                            cout << "\nInvalid input."<<endl;
                            cout << "Enter only using letters."<<endl;
                            cout << "Spaces are allowed."<<endl;
                            system("PAUSE");
                        }
                    }while(looper == 0);
}

string cardNumReset(){
                    int looper = 0;
                    do {
                    system("CLS");
                    cout<<"+---------------------------------------+"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"|                Payment                |"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"+---------------------------------------+"<<endl;
                    cout << "\nTypes of card (CREDIT/DEBIT): "<<typesOfCard<<endl;

                    cout << "\nName on card: "<<nameOfCard<<endl;

                    cout << "\nCard number: ";
                    getline(cin,cardNum);

                        if((cardNum.length()) < 24 && (cardNum.length()) > 11 ){ //Length starts from 1

                            if(!isLetters(cardNum) && isNumbers(cardNum) && !isPunct(cardNum)){

                                return cardNum;

                            }else{
                                cout << "\nInvalid input for card number."<<endl;
                                cout << "Enter only using digits from 0 to 9."<<endl;
                                cout << "Spaces are allowed." <<endl;
                                system("PAUSE");
                            }

                            }else{
                                cout << "\nInvalid length for card number."<<endl;
                                cout << "Spaces are allowed." <<endl;
                                system("PAUSE");
                            }
                    }while(looper == 0);
}

int expDateReset(){
                    int looper = 0;
                    do {
                    system("CLS");
                    cout<<"+---------------------------------------+"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"|                Payment                |"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"+---------------------------------------+"<<endl;
                    cout << "\nTypes of card (CREDIT/DEBIT): "<<typesOfCard<<endl;

                    cout << "\nName on card: "<<nameOfCard<<endl;

                    cout << "\nCard number: "<<cardNum<<endl;

                    cout << "\nExpiration Date - Month  (MM): ";
                    getline(cin,expDateMonthStr);

                    cout << "                - Year (YYYY): ";
                    getline(cin,expDateYearStr);

                    if (!isLetters(expDateMonthStr)   && isNumbers(expDateMonthStr)   && !isPunct(expDateMonthStr)   && !isSpace(expDateMonthStr) &&
                        !isLetters(expDateYearStr)    && isNumbers(expDateYearStr)    && !isPunct(expDateYearStr)    && !isSpace(expDateYearStr)  ){

                        stringstream (expDateMonthStr) >> expDateMonth; //Converting String to Int
                        stringstream (expDateYearStr) >> expDateYear;

                    if ( expDateMonth >=1 && expDateMonth <= 12 && expDateYear >= 1000 && expDateYear <= 9999){

                        if ( expDateYear > purchaseYear ){

                            return expDateMonth,expDateYear;

                        }else if ( expDateYear == purchaseYear ){

                                if ( expDateMonth >= purchaseMonth ){

                                    return expDateMonth,expDateYear;

                                }else{
                                cout << "\nInvalid input."<<endl;
                                cout << "Your card has expired."<<endl;
                                system("PAUSE");
                                }

                        }else{
                        cout << "\nInvalid input."<<endl;
                        cout << "Your card has expired."<<endl;
                        system("PAUSE");
                        }

                    }else{
                        cout << "\nInvalid input."<<endl;
                        cout << "Enter a proper date without spaces with the format of: "<<endl;
                        cout << "Month: MM"<<endl;
                        cout << "Year : YYYY"<<endl;
                        system("PAUSE");
                    }

                    }else{
                        cout << "\nInvalid input."<<endl;
                        cout << "Enter a proper date without any spaces."<<endl;
                        system("PAUSE");
                    }
                }while(looper == 0);
}

string cvvReset(){
                    int looper = 0;
                    do {
                    system("CLS");
                    cout<<"+---------------------------------------+"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"|                Payment                |"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"+---------------------------------------+"<<endl;

                    cout << "\nTypes of card (CREDIT/DEBIT): "<<typesOfCard<<endl;

                    cout << "\nName on card: "<<nameOfCard<<endl;

                    cout << "\nCard number: "<<cardNum<<endl;

                    cout << "\nExpiration Date - Month  (MM): "<<expDateMonth<<endl;

                    cout << "                - Year (YYYY): "<<expDateYear<<endl;

                    cout << "\nCard verification value (CVV): ";
                     getline(cin,cvv);

                        if( (cvv.length()) > 2 && (cvv.length()) < 5){

                            if(!isLetters(cvv) && isNumbers(cvv) && !isPunct(cvv) && !isSpace(cvv)){

                        return cvv;

                    }else{
                        cout << "\nInvalid input."<<endl;
                        cout << "Enter only using digits from 0 to 9."<<endl;
                        cout << "No spaces are allowed."<<endl;
                        system("PAUSE");
                    }

                    }else{
                        cout << "\nInvalid input."<<endl;
                        cout << "Enter a valid CVV with a proper length (3 or 4 numbers)."<<endl;
                        cout << "No spaces are allowed."<<endl;
                        system("PAUSE");
                    }
                }while(looper == 0);
}

//-----Reference Number Generator-----------------------------------------------------------------------

 static int getRefNumIntNew(){
        static int refNumIntNew = 1;
        return refNumIntNew++; // it returns the refNumIntNew first then only undergoes increment by 1
    }

//---------------------------Transaction history -------------------------------------------------

void fillVector (vector<TransactionHistory>& vectorHistory){ //Call by reference to reduce memory usage

    TransactionHistory newRec (refNumStr, refNumInt, // Pass data into the member variables of 'newRec' (object) through overload constructor
                               purchaseDay, purchaseMonth, purchaseYear,
                               numOfParks,
                               parkIDList2,
                               numTickets,
                               validOfExP,
                               validDay, validMonth, validYear,
                               totalPrice,
                               gifts);
                               vectorHistory.push_back(newRec); // Insert 'newRec' (object) along with its member variables into the vector
}

void printTransactionHistory(const vector<TransactionHistory>& vectorHistory){
                            historyReset:
                            system("CLS");
                            cout<<"+--------------------------------------------------+"<<endl;
                            cout<<"|                                                  |"<<endl;
                            cout<<"|                Transaction History               |"<<endl;
                            cout<<"|                                                  |"<<endl;
                            cout<<"+--------------------------------------------------+"<<endl;
                            cout << "\n";

                            cout <<"No           Reference number            Purchase Date"<<endl;

                            for (unsigned int i = 0 ; i < vectorHistory.size() ; i++){ //Size is always positive, thus unsigned int is used, size() starts with 1.

                                cout <<i+1<<"            "<<vectorHistory[i].getRefNumStr()<<vectorHistory[i].getRefNumInt()<<"                         "<<
                                vectorHistory[i].getPurchaseDay()<<"/"<<vectorHistory[i].getPurchaseMonth()<<"/"<<vectorHistory[i].getPurchaseYear()<<endl;\
                            }

                            cout << "\nEnter a number for more transaction details."<<endl;
                            cout << "Enter '0' to go back to guest menu."<<endl;
                            getline(cin,anyKey);
                                if (anyKey != "0"){

                                    if (!isSpace(anyKey) && !isLetters(anyKey) && !isPunct(anyKey) &&isNumbers(anyKey)){

                                        stringstream (anyKey) >> anyKeyInt; //Converting String to Int

                                            if (anyKeyInt <= vectorHistory.size()){

                                                anyKeyInt--;

//-----Details of transaction history-----------------------------------------------------------------------

                                    do {
                                        system("CLS");
                                        cout<<"+--------------------------------------------------+"<<endl;
                                        cout<<"|                                                  |"<<endl;
                                        cout<<"|                Transaction History               |"<<endl;
                                        cout<<"|                                                  |"<<endl;
                                        cout<<"+--------------------------------------------------+"<<endl;
                                        cout << "\n";

                                        cout << "Reference number: " << vectorHistory[anyKeyInt].getRefNumStr() << vectorHistory[anyKeyInt].getRefNumInt() <<endl;
                                        cout << "\nPurchase date: " << vectorHistory[anyKeyInt].getPurchaseDay() << "/" << vectorHistory[anyKeyInt].getPurchaseMonth() << "/" << vectorHistory[anyKeyInt].getPurchaseYear() <<endl;
                                        cout << "\nNumber of parks: " << vectorHistory[anyKeyInt].getNumOfParks() <<endl;
                                        cout << "\nPurchased park ID: "<< vectorHistory[anyKeyInt].getParkIDList2() <<endl;
                                        cout << "\nNumber of tickets: " << vectorHistory[anyKeyInt].getNumTickets() <<endl;
                                        cout << "\nValidity of express pass: " << vectorHistory[anyKeyInt].getValidOfExP() <<endl;
                                        cout << "\nValid date: " << vectorHistory[anyKeyInt].getValidDay() << "/" << vectorHistory[anyKeyInt].getValidMonth() << "/" << vectorHistory[anyKeyInt].getValidYear() <<endl;
                                        cout << "\nTotal price: RM" << vectorHistory[anyKeyInt].getTotalPrice() <<endl;
                                        cout << "\nGifts: " << vectorHistory[anyKeyInt].getGifts() <<endl;

                                        cout << "\nEnter 'X' to go back to Transaction History." <<endl;
                                        cout << "Enter '0' to go back to guest menu." <<endl;
                                        getline(cin,anyKey);

                                        if (anyKey == "X" || anyKey == "x"){

                                                goto historyReset;

                                        }else if( anyKey == "0" ){

                                                return;

                                        }else{

                                               cout << "\nInvalid input."<<endl;
                                               system("PAUSE");
                                               anyKey = "Loop back to Rec of details.";
                                        }

                                    }while(anyKey != "X" && anyKey != "x" && anyKey != "0");

                                }else{
                                    cout << "\nInvalid input."<<endl;
                                    cout << "You have not made sufficient amount of transaction."<<endl;
                                    system("PAUSE");
                                    goto historyReset;
                                }

                                }else{
                                    cout << "\nInvalid input."<<endl;
                                    cout << "Enter only valid numbers for more transaction details"<<endl;
                                    cout << "or enter only digit '0' to go back to menu."<<endl;
                                    cout << "No spaces are allowed."<<endl;
                                    system("PAUSE");
                                    goto historyReset;
                                }

                                }else if (anyKey == "0"){

                                    return;

                                }else{

                                    cout << "\nInvalid input."<<endl;
                                    cout << "Enter only valid numbers for more transaction details"<<endl;
                                    cout << "or enter only digit '0' to go back to menu."<<endl;
                                    system("PAUSE");
                                    goto historyReset;
                                }
}

//---------------------------------------------------------------------------------------------------------

int main()
{
system("Color 0E");  // 0= black background , E= light yellow text
ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

Admin defaultAccount ("admin","12345",30,4,2020);
List.push_back(defaultAccount);

Park park1 ("EXTREME PARK", 1);
parkList.push_back(park1);
Park park2 ("WATER PARK" , 2);
parkList.push_back(park2);
Park park3 ("WILDLIFE PARK" , 3);
parkList.push_back(park3);


mainMenu:
    system("CLS");
    string number;
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|              Welcome to WAKY Theme Park!              |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl<<endl;

    cout<<"                   1. Admin Access                       "<<endl;
    cout<<"                   2. Guest Access                       "<<endl;
    cout<<"                   3. Exit                               "<<endl;
    cout<<"                                                         "<<endl;
    cout<<"Enter a number: ";
    getline(cin,number);

     if(!isLetters(number) && isNumbers(number) && !isPunct(number) && !isSpace(number)){
           int choiceNum;
            stringstream (number) >> choiceNum;

        if (choiceNum == 1){

       loginMenu:
       system("CLS");
    cout<<"+-------------------------------------------------------+"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"|                     Admin Access                      |"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"+-------------------------------------------------------+"<<endl<<endl;

       // default username: admin , default password: 12345
       string inputUsername;
       cout << "Enter Username: ";
       getline(cin,inputUsername);

       if(!isPunct(inputUsername) && !isSpace(inputUsername) ){

       }else{

            cout<<"\nInvalid username and password.";
            cout<<"\nNo spaces and punctuations are allowed.\n";
            system("PAUSE");
            goto loginMenu;
       }

       string inputPassword;
       cout << "\nEnter Password: ";
       getline(cin,inputPassword);

        int looper = 0;
        while (looper == 0){

            if (adminCheck(List,inputUsername,inputPassword)){
                goto adminMenu;

                looper = 1;

            }else{

                cout <<"\nInvalid username and password.";
                cout<<"\nEnter any key to retry.";
                cout<<"\nEnter '0' to go back to main menu.\n";
                getline(cin,anyKey);

                    if(anyKey =="0"){

                        goto mainMenu;

                    }else{

                        goto loginMenu;

                    }
            }
        }

        adminMenu:
        system ("CLS");
        cout<<"+-------------------------------------------------------+"<<endl;
        cout<<"|                                                       |"<<endl;
        cout<<"|                      Admin Menu                       |"<<endl;
        cout<<"|                                                       |"<<endl;
        cout<<"+-------------------------------------------------------+"<<endl<<endl;

        cout<<"                1. Add Admin Account                     "<<endl;
        cout<<"                2. Display Admin List                    "<<endl;
        cout<<"                3. Add Park                              "<<endl;
        cout<<"                4. Adjust Ticket Price                   "<<endl;
        cout<<"                5. Adjust Promotions and Gifts           "<<endl;
        cout<<"                6. Log out                               "<<endl;
        cout<<"                                                         "<<endl;
        cout<<"Enter a number: ";

        string choice;
        getline(cin,choice);

        if( !isLetters(choice) && isNumbers(choice) && !isPunct(choice) && !isSpace(choice) ){
                    int number;
                    stringstream (choice) >> number ;

                if (number == 1){
                    addAdminMain:
                    do{
                    usernameReset(List);
                    passwordReset(List);

                    addAdminReset:
                    system("CLS");
                    cout<<"+-------------------------------------------------------+"<<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<"|                   Add Admin Account                   |"<<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<"+-------------------------------------------------------+"<<endl;

                    cout <<"\nEnter new username: "<<username;

                    cout << "\n\nEnter new password: "<<password<<endl;

                    cout<<"\nConfirm to create new admin account? (Y/N): ";
                    getline(cin,anyKey);

                    if(anyKey == "Y" || anyKey == "y"){

                    cout<<"\nEnter any key to proceed."<<endl;
                    cout<<"Enter '0' to go back to admin menu."<<endl;
                    getline(cin,anyKey);

                        if(anyKey !="0"){
                        fillList(List);
                        system("CLS");
                        cout<<"+-------------------------------------------------------+"<<endl;
                        cout<<"|                                                       |"<<endl;
                        cout<<"|                   Add Admin Account                   |"<<endl;
                        cout<<"|                                                       |"<<endl;
                        cout<<"+-------------------------------------------------------+"<<endl<<endl;

                        cout<<"Successfully Added New Admin Account!"<<endl<<endl<<endl;
                        system("PAUSE");
                        goto adminMenu;

                        }else{
                            goto adminMenu;
                        }

                    }else if(anyKey == "N" || anyKey == "n"){
                        goto addAdminMain;


                    }else{
                    cout<<"\nInvalid input."<<endl;
                    cout<<"Enter 'Y' or 'N' to proceed or to decline changes."<<endl;
                    system("PAUSE");
                    goto addAdminReset;
                    }

                    }while (anyKey != "N" && anyKey != "n" && anyKey!= "Y" && anyKey!= "y" && anyKey!="0");

                }else if (number == 2){

                    printList:
                    printList(List);
                    cout<<"\nEnter '0' to go back to admin menu."<<endl;
                    getline(cin,anyKey);
                    if (anyKey == "0"){

                        goto adminMenu;

                    }else{

                        cout<<"\nInvalid input."<<endl;
                        system("PAUSE");
                        system("CLS");
                        goto printList;

                    }
                }

                else if (number == 3){
                addParkMain:
                do{
                parkID = getParkID('+');
                parkNameReset(parkList);

                addParkReset:
                system("CLS");
                cout<<"+-------------------------------------------------------+"<<endl;
                cout<<"|                                                       |"<<endl;
                cout<<"|                       Add Park                        |"<<endl;
                cout<<"|                                                       |"<<endl;
                cout<<"+-------------------------------------------------------+"<<endl;

                cout<<"\nEnter new park name: "<<parkName<<endl;

                cout<<"\n          Park ID  : TP"<<parkID<<endl;

                cout<<"\nConfirm to create new park? (Y/N): ";
                        getline(cin,anyKey);

                        if(anyKey == "Y" || anyKey == "y"){

                        cout<<"\nEnter any key to proceed."<<endl;
                        cout<<"Enter '0' to go back to admin menu."<<endl;
                        getline(cin,anyKey);

                            if(anyKey !="0"){
                                fillPark(parkList);
                                system("CLS");
                                cout<<"+-------------------------------------------------------+"<<endl;
                                cout<<"|                                                       |"<<endl;
                                cout<<"|                       Add Park                        |"<<endl;
                                cout<<"|                                                       |"<<endl;
                                cout<<"+-------------------------------------------------------+"<<endl<<endl;

                                cout<<"Successfully Added New Park!"<<endl<<endl<<endl;
                                system("PAUSE");
                                goto adminMenu;

                            }else{
                                getParkID('-');
                                goto adminMenu;
                            }

                        }else if (anyKey == "N" || anyKey == "n"){
                            getParkID('-');
                            goto addParkMain;


                        }else{
                            cout<<"\nInvalid input."<<endl;
                            cout<<"Enter 'Y' or 'N' to proceed or to decline changes."<<endl;
                            system("PAUSE");
                            goto addParkReset;
                        }

                }while (anyKey != "N" && anyKey != "n" && anyKey!= "Y" && anyKey!= "y" && anyKey!="0");

                }else if(number == 4){
                        system("CLS");
                        ticketPriceMain:
                        do{ childTicketPriceReset();
                            adultTicketPriceReset();
                            seniorTicketPriceReset();

                            ticketPricePrint:
                            system("CLS");
                            cout<<"+-------------------------------------------------------+"<<endl;
                            cout<<"|                                                       |"<<endl;
                            cout<<"|                  Adjust Ticket Price                  |"<<endl;
                            cout<<"|                                                       |"<<endl;
                            cout<<"+-------------------------------------------------------+"<<endl;

                            cout<<"\nNote: Children (12 years old and below)"<<endl;
                            cout<<"      Adults   (13 years old and above)"<<endl;
                            cout<<"      Seniors  (60 years old and above)"<<endl;

                            cout<<"\nCurrent Ticket Price (Children): RM"<<childTicketPrice<<endl;
                            cout<<"                     (Adults)  : RM"<<adultTicketPrice<<endl;
                            cout<<"                     (Seniors) : RM"<<seniorTicketPrice<<endl;

                            cout<<"\nNew Ticket Price     (Children): RM"<<newChildTicketPrice<<endl;
                            cout<<"                     (Adults)  : RM"<<newAdultTicketPrice<<endl;
                            cout<<"                     (Seniors) : RM"<<newSeniorTicketPrice<<endl;

                            if ((newChildTicketPrice == childTicketPrice) && (newAdultTicketPrice == adultTicketPrice) && (newSeniorTicketPrice == seniorTicketPrice)){
                                cout<<"\nPlease make at least one adjustment to the ticket price."<<endl;
                                system("PAUSE");
                                goto ticketPriceMain;

                            }else{
                                cout<<"\nConfirm to proceed changes? (Y/N): ";
                                getline(cin,anyKey);

                                    if(anyKey  == "Y" || anyKey =="y" ){
                                    cout<<"\nEnter any key to proceed."<<endl;
                                    cout<<"Enter '0' to go back to admin menu."<<endl;
                                    getline(cin,anyKey);

                                        if(anyKey =="0"){
                                            goto adminMenu;

                                        }else{
                                        childTicketPrice = newChildTicketPrice;
                                        adultTicketPrice = newAdultTicketPrice;
                                        seniorTicketPrice = newSeniorTicketPrice;

                                        system("CLS");
                                        cout<<"+-------------------------------------------------------+"<<endl;
                                        cout<<"|                                                       |"<<endl;
                                        cout<<"|                  Adjust Ticket Price                  |"<<endl;
                                        cout<<"|                                                       |"<<endl;
                                        cout<<"+-------------------------------------------------------+"<<endl<<endl;

                                        cout<<"Successfully Adjusted Ticket Price!"<<endl<<endl<<endl;
                                        system("PAUSE");
                                        goto adminMenu;
                                        }

                                    }else if(anyKey  == "N" || anyKey  == "n"){
                                        goto ticketPriceMain;

                                    }else
                                     cout<<"\nInvalid input."<<endl;
                                     cout<<"Enter 'Y' or 'N' to proceed or to decline changes."<<endl;
                                     system("PAUSE");
                                     goto ticketPricePrint;
                            }

                        }while ((anyKey == "N" || anyKey == "n") && anyKey!= "Y" && anyKey!= "y" && anyKey!="0");


                }else if(number == 5){

                    adjustMenu:
                    system("CLS");
                    cout<<"+-------------------------------------------------------+"<<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<"|               Adjust Promotions & Gifts               |"<<endl;
                    cout<<"|                                                       |"<<endl;
                    cout<<"+-------------------------------------------------------+"<<endl;

                    cout<<"\n1. Buy tickets with access to "<<minPurchase<<" parks at once for " <<discountRate_1<<"% off."<<endl;
                    cout<<"\n2. Purchase tickets over RM"<<minTotalPrice<<" to get up to RM"<<valueOfGift<<" worth of "<<typeOfGift<<" voucher."<<endl;
                    cout<<"\n3. Upcoming discount - "<<eventName <<"\n   - All tickets "<<discountRate_2<<"% off on "<<oldEventDay<<"/"<<oldEventMonth<<"/"<<oldEventYear<<"!"<<endl;
                    cout<<"\nEnter '0' to go back to admin menu.\n\n";
                    cout<<"Enter a number : ";
                    string selectNum;
                    getline(cin,selectNum);

                    if(isNumbers(selectNum) && !isLetters(selectNum) && !isPunct(selectNum) && !isSpace(selectNum)&&
                       (selectNum =="3" || selectNum =="2" ||selectNum=="1" || selectNum =="0")){

                        if (selectNum == "1" ){

                            do{

                            promo1Reset:
                            minPurchaseReset();
                            discountRateReset();

                            while(looper2==0){
                              if ( repetitionCheck ( minPurchase,discountRate_1 )){
                                goto promo1Print;

                            }else{
                                cout<<"\nInvalid input."<<endl;
                                cout<<"Do not enter same min park purchase"<<endl;
                                cout<<"and discount value at the same time."<<endl;
                                system("PAUSE");
                                minPurchaseReset();
                                discountRateReset();

                                }

                            }

                            promo1Print:
                            system("CLS");
                            cout<<"+-------------------------------------------------------+"<<endl;
                            cout<<"|                                                       |"<<endl;
                            cout<<"|               Adjust Promotions & Gifts               |"<<endl;
                            cout<<"|                                                       |"<<endl;
                            cout<<"+-------------------------------------------------------+"<<endl<<endl;

                            cout<<"Current Promotions & Gifts:                    "<<endl;
                            cout<<"Buy tickets with access to "<<minPurchase<<" parks at once"<<endl;
                            cout<<"for "<<discountRate_1<<"% off."<<endl;

                            cout<<"\nCurrent Min Park Purchase: "<<minPurchase;
                            cout<<"\nNew Min Park Purchase    : "<<newMinPurchase;

                            cout<<"\n\nCurrent Discount value: "<<discountRate_1;
                            cout<<"\nNew Discount value (%): "<<newDiscountRate_1;

                            cout<<"\n\nResult:";
                            cout<<"\nBuy tickets with access to "<<newMinPurchase<<" parks at once"<<endl;
                            cout<<"for "<<newDiscountRate_1<<"% off."<<endl;

                            cout<<"\nConfirm to proceed changes? (Y/N): ";
                            getline(cin,anyKey);

                                if (anyKey == "Y"||anyKey == "y"){

                                cout<<"\nEnter any key to proceed."<<endl;
                                cout<<"Enter '0' to go back to previous page."<<endl;
                                getline(cin,anyKey);

                                        if(anyKey == "0"){

                                            goto adjustMenu;

                                            }else{
                                                minPurchase=newMinPurchase;
                                                discountRate_1=newDiscountRate_1;

                                                system("CLS");
                                                cout<<"+-------------------------------------------------------+"<<endl;
                                                cout<<"|                                                       |"<<endl;
                                                cout<<"|               Adjust Promotions & Gifts               |"<<endl;
                                                cout<<"|                                                       |"<<endl;
                                                cout<<"+-------------------------------------------------------+"<<endl<<endl;

                                                cout<<"Successfully Adjusted Promotions & Gifts!"<<endl<<endl<<endl;
                                                system("PAUSE");
                                                goto adjustMenu;

                                                }


                                    }else if (anyKey == "N"||anyKey == "n"){

                                            goto promo1Reset;


                                    }else{

                                        cout<<"\nInvalid input."<<endl;
                                        cout<<"Enter 'Y' or 'N' to proceed or to decline changes."<<endl;
                                        system("PAUSE");
                                        goto promo1Print;

                                    }}while(anyKey=="n"||anyKey == "N");


                       }else if (selectNum == "2" ){
                            do{
                            promo2Reset:
                            ticketPriceReset();
                            giftReset();
                            giftValueReset();

                            while(looper2==0){
                            if ( repetitionCheck2 (minTotalPrice,typeOfGift,valueOfGift)){

                                goto promo2Print;

                            }else{

                            cout<<"\nInvalid input."<<endl;
                            cout<<"Do not enter same total ticket price,"<<endl;
                            cout<<"type of voucher and voucher value at the same time."<<endl;
                            system("PAUSE");
                            ticketPriceReset();
                            giftReset();
                            giftValueReset();

                            }
                            }

                            promo2Print:
                            system("cls");
                            cout<<"+-------------------------------------------------------+"<<endl;
                            cout<<"|                                                       |"<<endl;
                            cout<<"|               Adjust Promotions & Gifts               |"<<endl;
                            cout<<"|                                                       |"<<endl;
                            cout<<"+-------------------------------------------------------+"<<endl<<endl;

                            cout<<"Current Promotions & Gifts:                    "<<endl;
                            cout<<"Purchase tickets over RM"<<minTotalPrice<<" to get up"<<endl;
                            cout<<"to RM"<<valueOfGift<<" worth of "<<typeOfGift<<" voucher."<<endl;


                            cout<<"\nCurrent Total Ticket Price: RM"<<minTotalPrice;
                            cout<<"\nNew Total Ticket Price    : RM"<<newMinTotalPrice;

                            cout<<"\n\nCurrent Type of Voucher        : "<<typeOfGift;
                            cout<<"\nNew Type of Voucher (FOOD/GIFT): "<<typeOfGiftStr;

                            cout<<"\n\nCurrent Voucher Value: RM"<<valueOfGift;
                            cout<<"\nNew Voucher Value    : RM"<<newValueOfGift;

                            cout<<"\n\nResult: ";
                            cout<<"\nPurchase tickets over RM"<<newMinTotalPrice<<" to get up"<<endl;
                            cout<<"to RM"<<newValueOfGift<< " worth of "<<typeOfGiftStr<<" voucher."<<endl;

                            cout<<"\nConfirm to proceed changes? (Y/N): ";
                            getline(cin,anyKey);

                                    if (anyKey == "Y"||anyKey == "y"){

                                        cout<<"\nEnter any key to proceed.\n";
                                        cout<<"Enter '0' to go back to previous page.\n";
                                        getline(cin,anyKey);

                                            if(anyKey == "0"){

                                                goto adjustMenu;

                                            }else{
                                                minTotalPrice = newMinTotalPrice;
                                                typeOfGift = typeOfGiftStr;
                                                valueOfGift = newValueOfGift;

                                                system("CLS");
                                                cout<<"+-------------------------------------------------------+"<<endl;
                                                cout<<"|                                                       |"<<endl;
                                                cout<<"|               Adjust Promotions & Gifts               |"<<endl;
                                                cout<<"|                                                       |"<<endl;
                                                cout<<"+-------------------------------------------------------+"<<endl<<endl;

                                                cout<<"Successfully Adjusted Promotions & Gifts!"<<endl<<endl<<endl;
                                                system("PAUSE");
                                                goto adjustMenu;

                                            }


                                    }else if (anyKey == "N"||anyKey == "n"){

                                        goto promo2Reset;

                                    }else{

                                    cout<<"\nInvalid input."<<endl;
                                    cout<<"Enter 'Y' or 'N' to proceed or to decline changes."<<endl;
                                    system("PAUSE");
                                    goto promo2Print;
                                    }}while(anyKey=="n"||anyKey=="N");

                       }else if (selectNum == "3" ){

                        do{
                        promo3Reset:
                        eventNameReset();
                        discountRate2Reset();

                        while (looper2==0){
                              if ( repetitionCheck3 (eventName,discountRate_2)){

                                eventDateReset();
                                goto promo3Print;

                            }else{

                                cout<<"\nInvalid input."<<endl;
                                cout<<"Do not enter the same event name";
                                cout<<"\nand same discount value at the same time."<<endl;
                                system("PAUSE");
                                eventNameReset();
                                discountRate2Reset();
                        }
                        }

                        promo3Print:
                        system ("CLS");
                        cout<<"+-------------------------------------------------------+"<<endl;
                        cout<<"|                                                       |"<<endl;
                        cout<<"|               Adjust Promotions & Gifts               |"<<endl;
                        cout<<"|                                                       |"<<endl;
                        cout<<"+-------------------------------------------------------+"<<endl<<endl;

                        cout<<"Current Promotions & Gifts:                    "<<endl;
                        cout<<"Upcoming discount - "<<eventName<<"    "<<endl;
                        cout<<"- All tickets "<<discountRate_2<<"% off on "<<oldEventDay<<"/"<<oldEventMonth<<"/"<<oldEventYear<<"!"<<endl;

                        cout<<"\nCurrent Event Name: "<<eventName;
                        cout<<"\nNew Event Name    : "<<eventNameStr;

                        cout<<"\n\nCurrent Discount Value: "<<discountRate_2;
                        cout<<"\nNew Discount Value (%): "<<newDiscountRate_2;

                        cout<<"\n\nCurrent Date Eligible        : "<<oldEventDay<<"/"<<oldEventMonth<<"/"<<oldEventYear ;
                        cout<<"\nNew Date Eligible- Day   (DD): "<<eventDayStr<<endl;
                        cout<<"\n                - Month  (MM): "<<eventMonthStr<<endl;
                        cout<<"\n                - Year (YYYY): "<<eventYearStr;

                        cout<<"\n\nResult:";
                        cout<<"\nUpcoming discount - "<<eventNameStr<<endl;
                        cout<<"- All tickets "<<newDiscountRate_2<< "% off on "<<eventDayStr<<"/"<<eventMonthStr<<"/"<<eventYearStr<<"!"<<endl;

                        cout<<"\nConfirm to proceed changes? (Y/N): ";
                        getline(cin,anyKey);

                                    if (anyKey == "Y"||anyKey == "y"){
                                        cout<<"\nEnter any key to proceed.\n";
                                        cout<<"Enter '0' to go back to previous page.\n";
                                        getline(cin,anyKey);

                                            if(anyKey == "0"){

                                                goto adjustMenu;

                                            }else{
                                                eventName = eventNameStr;
                                                discountRate_2 = newDiscountRate_2;
                                                oldEventDay = eventDay;
                                                oldEventMonth = eventMonth;
                                                oldEventYear = eventYear;

                                                system("CLS");
                                                cout<<"+-------------------------------------------------------+"<<endl;
                                                cout<<"|                                                       |"<<endl;
                                                cout<<"|               Adjust Promotions & Gifts               |"<<endl;
                                                cout<<"|                                                       |"<<endl;
                                                cout<<"+-------------------------------------------------------+"<<endl<<endl;

                                                cout<<"Successfully Adjusted Promotions & Gifts!"<<endl<<endl<<endl;
                                                system("PAUSE");
                                                goto adjustMenu;

                                            }


                                    }else if (anyKey == "N"||anyKey == "n"){
                                        goto promo3Reset;

                                    }else{

                                        cout<<"\nInvalid input."<<endl;
                                        cout<<"Enter 'Y' or 'N' to proceed or to decline changes."<<endl;
                                        system("PAUSE");
                                        goto promo3Print;

                                    }}while(anyKey=="N"||anyKey=="n");

                       }else if(selectNum=="0"){

                            goto adminMenu;

                       }


                    }else{
                            cout<<"\nInvalid input."<<endl;
                            cout<<"Enter only number from 1 to 3."<<endl;
                            cout<<"Enter '0' to go back to admin menu."<<endl;
                            system("PAUSE");
                            system ("CLS");
                            goto adjustMenu;
                    }


                }else if(number ==6){
                      do{
                         system("CLS");
                        cout<<"+---------------------------------------------+"<<endl;
                        cout<<"|                                             |"<<endl;
                        cout<<"|                   Log Out                   |"<<endl;
                        cout<<"|                                             |"<<endl;
                        cout<<"+---------------------------------------------+"<<endl;

                        cout<<"\nConfirm to log out? (Y/N)"<<endl;
                        getline(cin,response);

                    if (response == "Y"||response == "y")
                    {
                        goto mainMenu;
                    }
                    else if (response == "N"||response == "n")
                    {
                        goto adminMenu;
                    }
                    else
                    {
                        cout<<"\nInvalid input."<<endl;
                        cout<<"Please enter 'Y' or 'N'."<<endl;
                        system ("PAUSE");
                    }

                }while (response != "Y" && response != "y" && response != "N" && response != "n");
                }
                else{
                    cout << "\nInvalid input."<<endl;
                    cout << "Enter only number from 1 to 6."<<endl;
                    cout << "No spaces are allowed."<<endl;
                    system("PAUSE");
                    goto adminMenu;
                }

        }else{
                    cout << "\nInvalid input."<<endl;
                    cout << "Enter only number from 1 to 6."<<endl;
                    cout << "No spaces are allowed."<<endl;
                    system("PAUSE");
                    goto adminMenu;
        }




        }else if (choiceNum == 2){
        resetMain:
        system("CLS");
        cout<<"+-------------------------------------------------------+"<<endl;
        cout<<"|                                                       |"<<endl;
        cout<<"|                      Guest Menu                       |"<<endl;
        cout<<"|                                                       |"<<endl;
        cout<<"+-------------------------------------------------------+"<<endl<<endl;

        cout<<"               1. Park List & Ticket Prices              "<<endl;
        cout<<"               2. Promotion & Gifts                      "<<endl;
        cout<<"               3. Ticketing                              "<<endl;
        cout<<"               4. Transaction History                    "<<endl;
        cout<<"               5. Log out                                "<<endl;
        cout<<"                                                         "<<endl;
        cout<<"Enter a number: ";

        getline (cin,selectionNumStr);

         if(!isLetters(selectionNumStr) && isNumbers(selectionNumStr) && !isPunct(selectionNumStr) && !isSpace(selectionNumStr)){

                int selectionNum;
                stringstream (selectionNumStr) >> selectionNum; //Converting String to Int

    //-------Num menu = 1 ----------------------------------------------------------------------------------------------------------------

             if(selectionNum == 1){
                    printPark (parkList);
                    goto resetMain;


        //-------Num menu = 2 ----------------------------------------------------------------------------------------------------------------

             }else if(selectionNum == 2){

                        do{
                           system ("CLS");
                                cout<<"+-----------------------------------------------------------------------+"<<endl;
                                cout<<"|                                                                       |"<<endl;
                                cout<<"|                          Promotions & Gifts                           |"<<endl;
                                cout<<"|                                                                       |"<<endl;
                                cout<<"+-----------------------------------------------------------------------+"<<endl;

                                cout<<"\n1. Buy tickets with access to "<<minPurchase<<" parks at once for " <<discountRate_1<<"% off."<<endl;
                                cout<<"\n2. Purchase tickets over RM"<<minTotalPrice<<" to get up to RM"<<valueOfGift<<" worth of "<<typeOfGift<<" voucher."<<endl;
                                cout<<"\n3. Upcoming discount - "<<eventName <<"\n   - All tickets "<<discountRate_2<<"% off on "<<oldEventDay<<"/"<<oldEventMonth<<"/"<<oldEventYear<<"!"<<endl;

                                cout<<"\nEnter '0' to go back to guest menu."<<endl;
                                getline(cin,anyKey);

                                if(anyKey == "0"){
                                    goto resetMain;

                                }else{
                                    cout<<"\nInvalid input."<<endl;
                                    system("PAUSE");
                                }

                        }while (anyKey != "0");

        //-------Num menu = 3 ----------------------------------------------------------------------------------------------------------------

                }else if(selectionNum == 3){

             do    {parkIDList.clear();
                    numOfParksReset(parkList);
                    parkIDReset1(parkList, parkIDList);

                    if(numOfParks >= 2){
                        parkIDReset2(parkList, parkIDList);

                        if(numOfParks == 3){
                            parkIDReset3(parkList, parkIDList);
                        }
                    }

                    validOfExPReset(parkList, parkIDList);
                    validDateReset(parkList, parkIDList);
                    numOfTicketsReset(parkList, parkIDList);

                cout << "\nEnter any key to proceed."<<endl;
                cout << "Enter '0' to go back to guest menu."<<endl;
                getline(cin,anyKey);

                    if (anyKey != "0" ){

                            system("CLS");
                    cout<<"+---------------------------------------+"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"|                Payment                |"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"+---------------------------------------+"<<endl;

                            if(validOfExP == "Y" || validOfExP == "y"){

                                validOfExP = "Yes";

                            }else{ //validOfExP == "N" || validOfExP == "n"

                                validOfExP = "No";

                            }

                            priceOfExPCal();
                            numTicketsCal();

                            subtotal = (((numChildren*childTicketPrice)+(numAdults*adultTicketPrice)+(numSeniors*seniorTicketPrice))*numOfParks)+ (numTickets*priceOfExP);

                            cout<<fixed<<showpoint;
                            cout << "\nSubtotal: RM" <<setprecision(2)<<subtotal<<endl;

                            discountCal();

                            cout << "\nDiscount: "<<discount<<"%"<<endl;

                            totalPrice = subtotal - (subtotal*discount/100);

                            cout<<fixed<<showpoint;
                            cout << "\nTotal price: RM"<<setprecision(2)<<totalPrice<<endl;

                            giftsCal();

                            cout << "\nGifts: " <<gifts<<endl;

                cout << "\nEnter any key to proceed with payment."<<endl;
                cout << "Enter 'X' to go back to ticketing."<<endl;
                getline(cin,anyKey);

                    if (anyKey != "x" && anyKey != "X" ){
                        typesOfCardReset();
                        nameOfCardReset();
                        cardNumReset();
                        expDateReset();
                        cvvReset();

                cout << "\nEnter any key to conclude payment."<<endl;
                cout << "Enter 'X' to go back to ticketing."<<endl;
                getline(cin,anyKey);

                    if (anyKey != "x" && anyKey != "X" ){

                            anyKey = "Moving to payment receipt"; //Quiting loop

                    }else{ //From Payment 3
                        anyKey = "x";
                    }

                    }else{ //From Payment 2
                        anyKey = "x";
                    }

                    }else{ //From Ticketing
                        goto resetMain;
                    }

                    }while(anyKey == "x" || anyKey == "X" );

                            system("CLS");
                    cout<<"+---------------------------------------+"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"|                Payment                |"<<endl;
                    cout<<"|                                       |"<<endl;
                    cout<<"+---------------------------------------+"<<endl;
                            cout<<"\nPayment Successful!"<<endl;
                            cout<<"Here's your receipt.\n"<<endl;

                            refNumInt = getRefNumIntNew();

                            parkIDList2Str.str(string()); // reset stringstream to null value

                            if (numOfParks == 1){
                                parkIDList2Str<< "TP"<<parkIDList[0];

                            }else if (numOfParks == 2){//(numOfParks >= 2){
                                parkIDList2Str<< "TP"<< parkIDList[0] << ", "<< "TP"<< parkIDList[1];

                            }else
                                parkIDList2Str<< "TP"<< parkIDList[0] << ", "<< "TP"<< parkIDList[1]<< ", "<< "TP"<< parkIDList[2];

                            parkIDList2 = parkIDList2Str.str();

                            if (typesOfCard == "CREDIT"){
                                refNumStr = "CT";
                                cout<< "Reference number : "<<refNumStr<<refNumInt<<endl;
                            } else {
                                // typesOfCard == "DEBIT"
                                refNumStr  = "DT";
                                cout<< "Reference number : "<<refNumStr<<refNumInt<<endl;
                            }

                            purchaseDateCal();
                            cout << "\nPurchase date: "<< purchaseDay <<"/"<<purchaseMonth<<"/"<<purchaseYear<<endl;

                            cout << "\nNumber of parks: "<<numOfParks<<endl;

                            cout << "\nPurchased park ID: "<<parkIDList2<<endl;

                            cout << "\nNumber of tickets: "<<numTickets<<endl;

                            cout << "\nValid date: "<< validDay <<"/"<<validMonth<<"/"<<validYear<<endl;

                            cout<<fixed<<showpoint;
                            cout << "\nTotal price: RM"<<setprecision(2)<<totalPrice<<endl;

                            cout << "\nGifts: "<<gifts<<endl;

                            fillVector(history);

                            parkIDList.clear();

                            cout << "\nThank you! "<<endl<<endl;
                            system ("PAUSE");
                            goto resetMain;

        //-------Num menu = 4 ----------------------------------------------------------------------------------------------------------------

                    }else if(selectionNum == 4){

                                 printTransactionHistory(history);
                                 goto resetMain;

        //-------Num menu = 5 ----------------------------------------------------------------------------------------------------------------

                    }else if(selectionNum == 5){

                    string response;
                        do{
                             system("CLS");
                            cout<<"+---------------------------------------------+"<<endl;
                            cout<<"|                                             |"<<endl;
                            cout<<"|                   Log Out                   |"<<endl;
                            cout<<"|                                             |"<<endl;
                            cout<<"+---------------------------------------------+"<<endl;

                            cout<<"\nConfirm to log out? (Y/N)"<<endl;
                            getline(cin,response);

                        if (response == "Y"||response == "y")
                        {
                            system ("CLS");
                            goto mainMenu;
                        }
                        else if (response == "N"||response == "n")
                        {
                            goto resetMain;
                        }
                        else
                        {
                            cout<<"\nInvalid input."<<endl;
                            cout<<"Please enter 'Y' or 'N'."<<endl;
                            system ("PAUSE");
                        }

                    }while (response != "Y" && response != "y" && response != "N" && response != "n");

        //----------------------------------------------------------------------------------------------------------------------

                    }else{
                        cout << "\nInvalid input."<<endl;
                        cout << "Enter only number from 1 to 5."<<endl;
                        cout << "No spaces are allowed."<<endl;
                        system("PAUSE");
                        goto resetMain;
                    }

                }else{
                    cout << "\nInvalid input."<<endl;
                    cout << "Enter only number from 1 to 5."<<endl;
                    cout << "No spaces are allowed."<<endl;
                    system("PAUSE");
                    goto resetMain;
                }


    }else if (choiceNum == 3){
        do{
                system("CLS");
                cout<<"+-------------------------------------------------------+"<<endl;
                cout<<"|                                                       |"<<endl;
                cout<<"|                         Exit                          |"<<endl;
                cout<<"|                                                       |"<<endl;
                cout<<"+-------------------------------------------------------+"<<endl;

                cout<<"\nAre you sure? (Y/N)"<<endl;
                getline(cin,response);

                    if (response == "Y"||response == "y"){
                        system ("CLS");
                        cout<<"+-------------------------------------------------------+"<<endl;
                        cout<<"|                                                       |"<<endl;
                        cout<<"|                         Exit                          |"<<endl;
                        cout<<"|                                                       |"<<endl;
                        cout<<"+-------------------------------------------------------+"<<endl;

                        cout<<"\nThank you for visiting us."<<endl;
                        cout<<"\nHave a great day!"<<endl;
                        exit(0);

                    }else if (response == "N"||response == "n"){
                        goto mainMenu;

                    }else{
                        cout<<"\nInvalid input."<<endl;
                        cout<<"Please enter 'Y' or 'N'."<<endl;
                        system ("PAUSE");
                    }

                }while (response != "Y" && response != "y" && response != "N" && response != "n");


}else {
    cout << "\nInvalid input."<<endl;
    cout << "Enter only number from 1 to 3."<<endl;
    cout << "No spaces are allowed."<<endl;
    system("PAUSE");
    goto mainMenu;
}

}else {
    cout << "\nInvalid input."<<endl;
    cout << "Enter only number from 1 to 3."<<endl;
    cout << "No spaces are allowed."<<endl;
    system("PAUSE");
    goto mainMenu;
}

}








