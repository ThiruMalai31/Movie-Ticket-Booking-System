#include <bits/stdc++.h>
using namespace std;
int totalAdmin=0,totalCustomer=0,totalTheatre=0,totalBooking=0;
class User
{
     string Name;
	 int Age;
	 string Gender;
	 string Dob;
	 string Password;
	 public:
	 string getPassword() {
		return Password;
	}
	void setPassword(string password) {
		Password = password;
	}
    string getName() {
		return Name;
	}
	void setName(string name) {
		Name = name;
	}
	int getAge() {
		return Age;
	}
    void setAge(int age) {
		Age = age;
	}
	string getGender() {
		return Gender;
	}
	void setGender(string gender) {
		Gender = gender;
	}
	string getDob() {
		return Dob;
	}
	void setDob(string dob) {
		Dob = dob;
	}
};
class Admin : public User
{

};
class Customer : public User
{

};
Admin adminDetails[10];
Customer customerDetails[10];
class Screen {
    private:
	string name;
	int **totalSeats;
	char**** seatList;
	string* date;
	string** movieName;
	string** showId;
	string** showTime;

	 int row,col,totalShow,dateSize;

   // vector<vector<int>> seatList(10, vector<int>(10,0));
	// int seatList[10][10];
	public:
    Screen()
    {

    }
	Screen(int row,int col,int dateSize,int totalShow)
	{
	    date=new string[dateSize];
        showTime=new string*[dateSize];
	    movieName=new string*[dateSize];
          showId=new string*[dateSize];
          totalSeats=new int*[dateSize];
	    for(int i=0;i<dateSize;i++)
        {
            movieName[i]=new string[totalShow];
            showId[i]=new string[totalShow];
            showTime[i]=new string[totalShow];
            totalSeats[i]=new int[totalShow];
        }
	    this->row=row;
	    this->col=col;
	    this->totalShow=totalShow;
	    this->dateSize=dateSize;
	    seatList=new char***[dateSize];
	    for(int i=0;i<dateSize;i++)
        {
            seatList[i]=new char**[totalShow];
            for(int j=0;j<totalShow;j++)
            {
                seatList[i][j]=new char*[row];
                for(int k=0;k<row;k++){
                seatList[i][j][k]=new char[col];
                }
            }
        }
        for(int d=0;d<dateSize;d++){
        for(int s=0;s<totalShow;s++){
	    for(int i=0; i<row;i++){
                for(int j=0;j<col;j++)
                {
                    seatList[d][s][i][j]='O';
                }
	    }
        }
        }



	}
public:
 /*   string getShowId() {
		return showId;
	}
    void setShowId(string showId) {
		this->showId = showId;
	}*/
	setDate(int dateind,string date)
	{
	    this->date[dateind]=date;
	}
	string* getDate()
	{
	    return date;
	}
	setShowId(int dateind,int showind,string id)
	{
	    showId[dateind][showind]=id;
	}
	string** getShowId() {
		return showId;
	}
	string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
/*	string getMovieName() {
		return movieName;
	}
	void setMovieName(string movieName) {
		this->movieName = movieName;
	} */
	setMovieName(int dateind,int showind,string movie)
	{
	    movieName[dateind][showind]=movie;
	}
	string** getMovieName()
	{
	    return movieName;
	}
	setShowTime(int dateind,int showind,string time)
	{
	    showTime[dateind][showind]=time;
	}
	string** getShowTime()
	{
	    return showTime;
	}
	setTotalSeats(int dateind,int showind,int seats)
	{
	    totalSeats[dateind][showind]=seats;
	}
	int** getTotalSeats() {
		return totalSeats;
	}
	int getRows()
	{
	    return row;
	}
	int getColumns()
	{
	    return col;
	}
	int getTotalShow()
	{
	    return totalShow;
	}
	int getTotalDates()
	{
	    return dateSize;
	}

	setSeatList(int date,int show,char chosenRow,int chosenColumn)
	{
	    seatList[date][show][chosenRow-'a'][chosenColumn-1]='X';
	}
	cancelSeatList(int date,int show,char chosenRow,int chosenColumn)
	{

	   // cout<<chosenRow<<" "<<chosenColumn<<endl;
	    seatList[date][show][chosenRow-'a'][chosenColumn-1]='O';

	}
    char**** getSeatList()
    {
        return seatList;
    }
};

class Theatre {
	string name;
	int totalScreens;
	Screen screens[10];

	public:

    string getName() {
		return name;
	}
	void setName(string name) {
		this->name = name;
	}
	int getTotalScreens() {
		return totalScreens;
	}
	void setTotalScreens(int totalScreens) {
		this->totalScreens = totalScreens;
	}

	Screen* getScreens() {
		return &screens[0];
	}


	 void setScreens(Screen screens[]) {
		for(int i=0;i<totalScreens;i++)
        {
            this->screens[i]=screens[i];
        }
	}

};
Theatre availableTheatres[10];
class AdminUtil
{
    public:
    void registerAdmin ()
	{
    //cout<<"st "<<adminDetails.size();
		Admin data;

		string name;
		cout<<"ENTER NAME   ";
		cin.ignore();
		getline(cin,name);
		data.setName(name);
		int age;
		cout<<"ENTER AGE   ";
		cin>>age;
		data.setAge(age);
		cin.ignore();
		string gender;
		cout<<"ENTER GENDER   ";
		getline(cin,gender);
		data.setGender(gender);
		string dob;
		cout<<"ENTER DOB   ";
		getline(cin,dob);
		data.setDob(dob);
		adminDetails[totalAdmin]=data;
		totalAdmin++;
	}
	int findUser(string name)
	{
	    Admin admin;
	    cout<<adminDetails[0].getName()<<endl;
        for(int i=0;i<totalAdmin;i++)
        {
            string nameChecker = adminDetails[i].getName();
          //  cout<<"wegwe "<<nameChecker<<name<<endl;
            if(nameChecker == name)
            {
                return 1;
                break;
            }
        }
        return 0;
	}
    void addTheatre() {

		cout<<"ENTER THEATRE NAME"<<endl;
		string theatreName;
		cin.ignore();
		getline(cin,theatreName);
		cout<<"ENTER TOTAL SCREENS"<<endl;
		int totalScreen;
        cin>>totalScreen;
		Theatre theatre ;
		theatre.setName(theatreName);
		theatre.setTotalScreens(totalScreen);
        cout<<"TOTAL DATES"<<endl;
        int totaldates,totalShows;
        cin>>totaldates;
        cout<<"TOTAL SHOWS PER DAY"<<endl;
        cin>>totalShows;
		Screen screens[totalScreen];

		for(int index = 0; index < totalScreen; index++) {
			string screenName;
			int row,col;
			cout<<"ENTER SCREEN NAME IN "<< theatre.getName()<<" ";
			cin.ignore();
			getline(cin,screenName);

			cout<<"ENTER TOTAL ROW IN "<<screenName<<" ";
			cin>>row;
			cout<<"ENTER TOTAL COLUMN IN "<<screenName<<" ";
			cin>>col;
          /*  cout<<"ENTER MOVIE NAME IN "<<screenName;
			cin>>movieName;*/
			Screen screen(row,col,totaldates,totalShows);
			screen.setName(screenName);
		//	screen.setMovieName(movieName);
		//	screen.setTotalSeats(row*col);
            for(int dateind=0;dateind<totaldates;dateind++){
                    cout<<"ENTER DATE "<<dateind+1<<" ";
                    string dates;
                    cin.ignore();
                    getline(cin,dates);
                    //cout<<endl;
                    screen.setDate(dateind,dates);
                    for(int showind=0;showind<totalShows;showind++)
                    {
                        string movieName,showTime;
                        cout<<"ENTER SHOW TIME FOR THE DATE "<<screen.getDate()[dateind]<<" IN "<<screen.getName()<<" ";
                       // cin.ignore();
                        getline(cin,showTime);
                        screen.setShowTime(dateind,showind,showTime);
                        cout<<"ENTER MOVIE NAME  FOR THE DATE "<<screen.getDate()[dateind]<<" AND TIME "<<showTime<<" ";
                      //  cin.ignore();
                        getline(cin,movieName);
                        screen.setMovieName(dateind,showind,movieName);

                        string showId = "#";
                        showId+= theatre.getName();
                        showId+="-";
                        showId+= screen.getName();
                        showId+= "-";
                        showId+= to_string(dateind+1);
                        showId+= to_string(showind+1);
                        screen.setShowId(dateind,showind,showId);
                        int seat=row*col;
                        screen.setTotalSeats(dateind,showind,seat);
                        cout<<endl;
                    }
            }

			screens[index]=screen;
		}
		theatre.setScreens(screens);

		availableTheatres[totalTheatre]=theatre;
		totalTheatre++;
	}
};
class UserUtil {
public:
	void displayTheatres(Theatre availableTheatres[],int totalTheatre) {
	    cout << setw(15) << "Id"
              << "|" << setw(15) << "Show ID"
              << "|" << setw(15) << "Theatre Name"
              << "|" << setw(15) << "Screen"
              << "|" << setw(15) << "Date"
              << "|" << setw(15) << "Time"
              << "|" << setw(15) << "Movie"
              << "|" << setw(15) << "Available Seats" << endl;
            cout<<endl;
		int currentId = 1;
		for (int i = 0; i <totalTheatre; i++) {
			Theatre details = availableTheatres[i];
			for (int j = 0; j < details.getTotalScreens(); j++) {
				Screen theatreScreen =  details.getScreens()[j];
            for(int dateind=0;dateind<theatreScreen.getTotalDates();dateind++){
                    for(int showind=0;showind<theatreScreen.getTotalShow();showind++){
				//cout<<"    ";
				cout<<setw(15)<<currentId;
				//cout<<"    ";
				currentId++;

				//cout<<"    ";
				cout<<"|"<<setw(15)<<theatreScreen.getShowId()[dateind][showind];
				//cout<<"    ";

				//cout<<"    ";
				cout<<"|"<<setw(15)<<details.getName();//<<setw(10);
				//cout<<"    ";

				//cout<<"    ";
				cout<<"|"<<setw(15)<<theatreScreen.getName();//<<setw(10);
				//cout<<"    ";

                //cout<<"    ";
                cout<<"|"<<setw(15)<<theatreScreen.getDate()[dateind];//<<setw(10);
				//cout<<"    ";

                //cout<<"    ";
                cout<<"|"<<setw(15)<<theatreScreen.getShowTime()[dateind][showind];//<<setw(10);
				//cout<<"    ";

				cout<<"|"<<setw(15)<<theatreScreen.getMovieName()[dateind][showind];//<<setw(10);
				//cout<<"    ";

				//cout<<"    ";
				cout<<"|"<<setw(15)<<theatreScreen.getTotalSeats()[dateind][showind];//<<setw(10);
				//cout<<"    ";

				cout<<endl;
				cout<<endl;
                    }
            }
			}

		}

		cout<<endl;
		cout<<endl;
	}



};
class Booking {
	Customer customer;
	Theatre theatre;
	Screen screen;
	int seats,dateind,showind,ticketCost;
	char* bookedRows;
	int* bookedColumns;
public:
    Booking()
    {

    }
    Booking(int noOfTickets)
    {
        bookedRows=new char[noOfTickets];
        bookedColumns=new int[noOfTickets];
        for(int i=0;i<noOfTickets;i++)
        {
            bookedRows[i]='z';
            bookedColumns[i]=0;
        }
    }
    Customer getCustomer() {
		return customer;
	}
	void setCustomer(Customer customer) {
		this->customer = customer;
	}
	Theatre getTheatre() {
		return theatre;
	}
	void setTheatre(Theatre theatre) {
		this->theatre = theatre;
	}

	Screen getScreen() {
		return screen;
	}
	void setScreen(Screen screen) {
		this->screen = screen;
	}
	int getSeats() {
		return seats;
	}
	void setSeats(int seats) {
		this->seats = seats;
	}
	setDateIndex(int date)
	{
	    dateind=date;
	}
	int getDateIndex()
	{
	    return dateind;
	}
	setShowIndex(int show)
	{
	    showind=show;
	}
	int getShowIndex()
	{
	    return showind;
	}
    void setRows(char rows[],int ind)
    {
        for(int i=0;i<ind;i++)
        {

            bookedRows[i]=rows[i];
        }
    }
    void setColumns(int columns[],int ind)
    {
        for(int i=0;i<ind;i++)
        {
            bookedColumns[i]=columns[i];
        }
    }
    char* getRows()
    {
        return &bookedRows[0];
    }

    int* getColumns()
    {
        return &bookedColumns[0];
    }
    setTicketCost(int cost)
    {
        ticketCost=cost;
    }
    getTicketCost()
    {
        return ticketCost;
    }
};
Booking bookingDetails[10];
class CustomerUtil
{
public:
    Customer findUser( string name)	{
		Customer customer;
        customer.setName(" ");
		for(int i=0;i<totalCustomer;i++)
		{
			string checkName = customerDetails[i].getName();
			if(checkName==name)
			{
				customer = (Customer) customerDetails[i];
				break;
			}
		}
		return customer;
    }

    void bookTicketsByTheatres(Customer & customer)  {

//		 /////////////////////////// XXXXXXXXXXXXXXXXXX      NEED PROPER ERROR HANDLING    XXXXXXXX    ////////////////////////////

		cout<<"ENTER THEATRE NAME :"<<endl;
		string theatreName;
		cin>>theatreName;
		string eligibleShowIds[20];

		Theatre *filteredAvailableTheatre[20];
		int totalFilteredTheatre=0,totalEligibleShowIds=0;
		for(int i=0;i<totalTheatre;i++)
		{
			Theatre *details = &availableTheatres[i];

			if(details->getName()==theatreName)
			{
				filteredAvailableTheatre[totalFilteredTheatre]=&availableTheatres[i];
				totalFilteredTheatre++;
			//	availableTheatres[i].setTotalScreens(5);

				for(int j=0;j<details->getTotalScreens(); j++) {
                        Screen screen=availableTheatres[i].getScreens()[j];
                    for(int dateind=0;dateind<screen.getTotalDates();dateind++){
                            for(int showind=0;showind<screen.getTotalShow();showind++){
					eligibleShowIds[totalEligibleShowIds]=details->getScreens()[j].getShowId()[dateind][showind];

					totalEligibleShowIds++;
                            }
                    }
				}
			}
		}

        UserUtil userUtil ;
    //    userUtil.displayTheatres(availableTheatres);
		userUtil.displayTheatres(*filteredAvailableTheatre,totalFilteredTheatre);
		cout<<"ENTER SHOWID :"<<endl;
		int chosenShow ;
		cin>>chosenShow;

		cout<<"ENTER NUMBER OF TICKETS :"<<endl;
		int numberOfTicket,totalTicketCost=0 ;
		cin>>numberOfTicket;
		cout<<"TICKET PRICE FOR SEAT A-C - 200"<<endl;
		cout<<"TICKET PRICE FROM SEAT D - 160"<<endl;
		string chosenShowId = eligibleShowIds[chosenShow-1];
         char chosenRows[numberOfTicket];
         int chosenColumns[numberOfTicket];
         int rowind=0,colind=0;
		Theatre finalChosenTheatre ;
		Screen finalChosenScreen ;
		int bookedDate,bookedShow;
		for(int i=0;i<totalTheatre; i++) {

			for(int j=0; j < availableTheatres[i].getTotalScreens(); j++) {

				Screen* currentScreen =&availableTheatres[i].getScreens()[j];

//                cnt++;
                     for(int dateind=0;dateind<currentScreen->getTotalDates();dateind++){
                            for(int showind=0;showind<currentScreen->getTotalShow();showind++){
				if(currentScreen->getShowId()[dateind][showind]== chosenShowId) {
                        bookedDate=dateind;
                bookedShow=showind;
                //cout<<"afsfas   "<<chosenShowId<<" "<<currentScreen->getShowId()[dateind][showind]<<endl;
                int seat=currentScreen->getTotalSeats()[dateind][showind]-numberOfTicket;
				currentScreen->setTotalSeats(dateind,showind,seat);
           //     cout<<currentScreen->getTotalSeats()<<endl;
                    cout<<"  ";
                    for(int num=1;num<=currentScreen->getColumns();num++)
                    {
                        cout<<num<<"  ";
                    }
                    cout<<endl;
                    char ch='a';
                    for(int z=0;z<currentScreen->getRows();z++)
                    {
                        cout<<ch<<" ";
                        for(int p=0;p<currentScreen->getColumns();p++)
                        {
                            cout<<currentScreen->getSeatList()[dateind][showind][z][p]<<"  ";
                        }
                        ch++;
                        cout<<endl;
                    }

                    for(int i=0;i<numberOfTicket;i++){
                    cout<<"CHOOSE ROW "<<endl;
                    char chosenRow;
                    cin>>chosenRow;
                    cout<<"CHOOSE COLUMN "<<endl;
                    int chosenColumn;
                    cin>>chosenColumn;
                    if(currentScreen->getSeatList()[dateind][showind][chosenRow-'a'][chosenColumn]!='X'){
                    //        cout<<"sdgsgd";
                    if(chosenRow<'d')
                    {
                        totalTicketCost+=200;
                    }
                    else
                    {

                        totalTicketCost+=160;
                    }
                    chosenRows[rowind++]=chosenRow;
                    chosenColumns[colind++]=chosenColumn;
                    currentScreen->setSeatList(dateind,showind,chosenRow,chosenColumn);}
                    else{
                        cout<<"SEAT IS ALREADY BOOKED.... BOOK ANOTHER SEAT";
                        i--;
                    }
                    }
                    cout<<"  ";
                    for(int num=1;num<=currentScreen->getColumns();num++)
                    {
                        cout<<num<<"  ";
                    }
                    cout<<endl;
                    ch='a';
                    for(int z=0;z<currentScreen->getRows();z++)
                    {
                        cout<<ch<<" ";
                        for(int p=0;p<currentScreen->getColumns();p++)
                        {
                            cout<<currentScreen->getSeatList()[dateind][showind][z][p]<<"  ";
                        }
                        ch++;
                        cout<<endl;
                    }
                    finalChosenTheatre = availableTheatres[i];
					finalChosenScreen = availableTheatres[i].getScreens()[j];
					break;
				}
                            }
                     }
			}
		}


        vector<Theatre> filteredAvailableTheatre1;
		for(int i=0;i<totalTheatre;i++)
		{
			Theatre details = availableTheatres[i];

			if(details.getName()==theatreName)
			{
				filteredAvailableTheatre1.push_back(availableTheatres[i]);

			}
		}

//		Booking successfully happeded after above logic
		Booking booking(numberOfTicket);
		booking.setCustomer(customer);
		booking.setTheatre(finalChosenTheatre);
		booking.setScreen(finalChosenScreen);
		booking.setSeats(numberOfTicket);
		booking.setRows(chosenRows,rowind);
		booking.setColumns(chosenColumns,colind);
		booking.setDateIndex(bookedDate);
		booking.setShowIndex(bookedShow);
		booking.setTicketCost(totalTicketCost);
		bookingDetails[totalBooking]=booking;
		totalBooking++;
        //filteredAvailableTheatre[chosenShow].getScreens()[cnt].setTotalSeats(40);
		userUtil.displayTheatres(*filteredAvailableTheatre,totalFilteredTheatre );
	}
    void bookTicketsByMovie(Customer customer)
    {
        string movieName;
        cout<<"ENTER MOVIE NAME"<<endl;
        cin>>movieName;

        string eligibleShowIds[20];
        Theatre filteredAvailableTheatre[10];
        int totalFilteredAvailableTheatres=0,totalEligibleShowIds=0;
        for(int i=0;i<totalTheatre;i++)
        {
            Theatre details=availableTheatres[i];
            for(int j=0;j<details.getTotalScreens();j++){
                    Screen screen=availableTheatres[i].getScreens()[j];
                    for(int dateind=0;dateind<screen.getTotalDates();dateind++){
                        for(int showind=0;showind<screen.getTotalShow();showind++){
            if(details.getScreens()[j].getMovieName()[dateind][showind]==movieName)
            {
                filteredAvailableTheatre[totalFilteredAvailableTheatres]=details;
                totalFilteredAvailableTheatres++;
                    eligibleShowIds[totalEligibleShowIds]=details.getScreens()[j].getShowId()[dateind][showind];
                    totalEligibleShowIds++;
            }
                            }
                                         }
            }
        }
        UserUtil userUtil ;
		userUtil.displayTheatres(filteredAvailableTheatre,totalFilteredAvailableTheatres);
		cout<<"ENTER SHOWID :"<<endl;
		int chosenShow ;
		cin>>chosenShow;

		cout<<"ENTER NUMBER OF TICKETS :"<<endl;
		int numberOfTicket,totalTicketCost=0 ;
		cin>>numberOfTicket;


		string chosenShowId = eligibleShowIds[chosenShow-1];
        char chosenRows[numberOfTicket];
         int chosenColumns[numberOfTicket];
         int rowind=0,colind=0;

		Theatre finalChosenTheatre ;
		Screen finalChosenScreen ;
		int bookedDate,bookedShow;
		for(int i=0;i<totalTheatre; i++) {
			for(int j=0; j < availableTheatres[i].getTotalScreens(); j++) {

				Screen* currentScreen =&availableTheatres[i].getScreens()[j];
            for(int dateind=0;dateind<currentScreen->getTotalDates();dateind++){
                            for(int showind=0;showind<currentScreen->getTotalShow();showind++){

				if(currentScreen->getShowId()[dateind][showind]== chosenShowId) {
				   bookedDate=dateind;
                bookedShow=showind;

                int seat=currentScreen->getTotalSeats()[dateind][showind]-numberOfTicket;
				currentScreen->setTotalSeats(dateind,showind,seat);

                    cout<<"  ";
                    for(int num=1;num<=currentScreen->getColumns();num++)
                    {
                        cout<<num<<"  ";
                    }
                    cout<<endl;
                    char ch='a';
                    for(int z=0;z<currentScreen->getRows();z++)
                    {
                        cout<<ch<<" ";
                        for(int p=0;p<currentScreen->getColumns();p++)
                        {
                            cout<<currentScreen->getSeatList()[dateind][showind][z][p]<<"  ";
                        }
                        ch++;
                        cout<<endl;
                    }

                    for(int i=0;i<numberOfTicket;i++){
                    cout<<"CHOOSE ROW "<<endl;
                    char chosenRow;
                    cin>>chosenRow;
                    cout<<"CHOOSE COLUMN "<<endl;
                    int chosenColumn;
                    cin>>chosenColumn;
                    if(currentScreen->getSeatList()[dateind][showind][chosenRow-'a'][chosenColumn]!='X'){
                    //        cout<<"sdgsgd";
                    if(chosenRow<'d')
                    {
                        totalTicketCost+=200;
                    }
                    else
                    {

                        totalTicketCost+=160;
                    }
                    chosenRows[rowind++]=chosenRow;
                    chosenColumns[colind++]=chosenColumn;
                    currentScreen->setSeatList(dateind,showind,chosenRow,chosenColumn);}
                    else{
                        cout<<"SEAT IS ALREADY BOOKED.... BOOK ANOTHER SEAT";
                        i--;
                    }
                    }
                    cout<<"  ";
                    for(int num=1;num<=currentScreen->getColumns();num++)
                    {
                        cout<<num<<"  ";
                    }
                    cout<<endl;
                    ch='a';
                    for(int z=0;z<currentScreen->getRows();z++)
                    {
                        cout<<ch<<" ";
                        for(int p=0;p<currentScreen->getColumns();p++)
                        {
                            cout<<currentScreen->getSeatList()[dateind][showind][z][p]<<"  ";
                        }
                        ch++;
                        cout<<endl;
                    }
                    finalChosenTheatre = availableTheatres[i];
					finalChosenScreen = availableTheatres[i].getScreens()[j];
					break;
				}
			}
            }
			}
		}



//		Booking successfully happeded after above logic
		Booking booking(numberOfTicket);
		booking.setCustomer(customer);
		booking.setTheatre(finalChosenTheatre);
		booking.setScreen(finalChosenScreen);
        booking.setSeats(numberOfTicket);
        booking.setRows(chosenRows,rowind);
		booking.setColumns(chosenColumns,colind);
		booking.setDateIndex(bookedDate);
		booking.setShowIndex(bookedShow);
		booking.setTicketCost(totalTicketCost);
		bookingDetails[totalBooking++]=booking;

		userUtil.displayTheatres(filteredAvailableTheatre,totalFilteredAvailableTheatres );

    }

	 void registerDetails()
	{

		Customer data;
		string name;
		cout<<"ENTER NAME"<<endl;
		cin>>name;
		data.setName(name);
		int age;
		cout<<"ENTER AGE"<<endl;
		cin>>age;
		data.setAge(age);
		string gender;
		cout<<"ENTER GENDER"<<endl;
		cin>>gender;
		data.setGender(gender);
		string dob;
		cout<<"ENTER DOB"<<endl;
		cin>>dob;
		data.setDob(dob);
		customerDetails[totalCustomer]=data;
		totalCustomer++;
	}

        void showBookingHistory(Customer & customer) {
        cout << setw(15) << "Id"
              << "|" << setw(15) << "Show ID"
              << "|" << setw(15) << "Customer Name"
              << "|" << setw(15) << "Theatre Name"
              << "|" << setw(15) << "Screen Name"
              << "|" << setw(15) << "Date"
              << "|" << setw(15) << "Time"
              << "|" << setw(15) << "Movie"
              << "|" << setw(15) << "Booked Seats" << endl;
            cout<<endl;

		cout<<endl;
		int currentId = 1;
		for (int i = 0; i < totalBooking; i++) {
			Booking details = bookingDetails[i];

			if(!(details.getCustomer().getName()==customer.getName())) {
				continue;
			}

            cout<<setw(15)<<currentId
            <<"|"<<setw(15)<<details.getScreen().getShowId()[details.getDateIndex()][details.getShowIndex()]
            <<"|"<<setw(15)<<customer.getName()
            <<"|"<<setw(15)<<details.getTheatre().getName()
            <<"|"<<setw(15)<<details.getScreen().getName()
			<<"|"<<setw(15)<<details.getScreen().getDate()[details.getDateIndex()]
			<<"|"<<setw(15)<<details.getScreen().getShowTime()[details.getDateIndex()][details.getShowIndex()]
			<<"|"<<setw(15)<<details.getScreen().getMovieName()[details.getDateIndex()][details.getShowIndex()]
			<<"|"<<setw(15)<<details.getSeats();

			cout<<endl;
            currentId++;
			cout<<"             BOOKED SEATS  ";
			int tickets=0;
			while(tickets!=details.getSeats())
            {
                cout<<details.getRows()[tickets]<<details.getColumns()[tickets]<<" ";
                tickets++;
            }
            cout<<"             TICKET COST  "<<details.getTicketCost();
            cout<<endl;
            cout<<endl;
		}

		cout<<endl;
		cout<<endl;
	}

	void cancelTicket(Customer &customer )
    {
        showBookingHistory(customer);
        cout<<"ENTER ID: ";
        int id,cnt=-1;
        cin>>id;
        for(int i=0;i<totalBooking;i++){
            Booking *details=&bookingDetails[i];
            if(!(details->getCustomer().getName()==customer.getName()))
            {
                continue;
            }
            cnt++;
            if(cnt==id-1)
            {
               // details->getScreen().setTotalSeats(details->getScreen().getTotalSeats()+details->getSeats());
               for(int i=0;i<totalTheatre;i++)
               {
                    Theatre *addList=&availableTheatres[i];
                    if(addList->getName()==details->getTheatre().getName())
                    {
                        for(int j=0;j<addList->getTotalScreens();j++)
                        {
                            if(addList->getScreens()[j].getName()==details->getScreen().getName()){
                                    addList->getScreens()[j].setTotalSeats(details->getDateIndex(),details->getShowIndex(),addList->getScreens()[j].getTotalSeats()[details->getDateIndex()][details->getShowIndex()]+details->getSeats());
                                    for(int set=0;set<details->getSeats();set++)
                                    {

                                        cout<<details->getRows()[set]<<" "<<details->getColumns()[set]<<endl;
                                        addList->getScreens()[j].cancelSeatList(details->getDateIndex(),details->getShowIndex(),details->getRows()[set],details->getColumns()[set]);

                                    }

                                    for(int r=0;r<addList->getScreens()[j].getRows();r++)
                                    {

                                        for(int c=0;c<addList->getScreens()[j].getColumns();c++)
                                        {

                                            cout<<addList->getScreens()[j].getSeatList()[details->getDateIndex()][details->getShowIndex()][r][c]<<" ";

                                        }
                                        cout<<endl;
                                    }

                            }
                        }
                    }
               }

                for(int b=i;b<totalBooking-1;b++)
                {
                    bookingDetails[b]=bookingDetails[b+1];
                }
                totalBooking--;

            }
        }
        showBookingHistory(customer);
    }
};



int main()
{

    cout<<"WELCOME TO BOOK MY SHOW"<<endl;
    int userType;
    do{
        cout<<"WELCOME"<<endl;
        cout<<"1.Admin"<<endl;
        cout<<"2.User"<<endl;
        cout<<"3.Exit"<<endl;
        cin>>userType;
        AdminUtil adminUtil;
        UserUtil userUtil;
        Admin currentAdmin;
        int selectedOperation=3;
        switch(userType)
        {
            case 1:{
                int adminSelectedOperation,set=0;
                cout<<"CHOOSE OPERATIONS "<<endl;
                cout<<"1.LOGIN"<<endl;
                cout<<"2.REGISTER"<<endl;
                cout<<"3.EXIT"<<endl;
                cin>>adminSelectedOperation;
                switch(adminSelectedOperation)
                {
                    case 1:{
                        do{
                            Admin adminData;
                            string name,password;
                            cout<<"ENTER NAME   ";
                            cin.ignore();
                            getline(cin,name);
                            cout<<"ENTER PASSWORD  ";
                            getline(cin,password);
                            adminData.setName(name);

                            adminData.setPassword(password);
                            set=adminUtil.findUser(name);
                          //  cout<<set<<endl;
                            if(set==0)
                            {
                                cout<<"ENTER VALID USERNAME"<<endl;
                            }


                        }while(set==0);
                        do{
                            cout<<"CHOOSE ANY OPERATIONS"<<endl;
                            cout<<"1.ADD THEATRE DETAILS"<<endl;
                            cout<<"2.DISPLAY THEATRE DETAILS"<<endl;
                            cout<<"3.EXIT"<<endl;
                            cin>>adminSelectedOperation;
                            switch(adminSelectedOperation)
                            {
                                case 1:
                                    adminUtil.addTheatre();
                                    break;
                                case 2:
                                    userUtil.displayTheatres(availableTheatres,totalTheatre);
                            }
                        }while(adminSelectedOperation!=3);
                        break;
                    }
                case 2:{
                    adminUtil.registerAdmin();
                 //   cout<<adminDetails[0].getName();
                    break;}
                default:
                    break;
                }
            break;
            }
            case 2:{

					do {

						 cout<<"CHOOSE OPERATIONS "<<endl;
                         cout<<"1.LOGIN"<<endl;
                         cout<<"2.REGISTER"<<endl;
                         cout<<"3.EXIT"<<endl;
						CustomerUtil customerUtil;
						Customer currentCustomer;
						currentCustomer.setName(" ");
						//Customer *check=&currentCustomer;
						//check=NULL;
						cin>>selectedOperation;
						switch(selectedOperation)
						{
						case 1:{
                            int set=0;
							do {
							Customer data;
							string name;
							cout<<"ENTER NAME     "<<endl;
							cin.ignore();
							getline(cin,name);
							data.setName(name);
							string password;
							cout<<"ENTER PASSWORD"<<endl;
							cin>>password;
							data.setPassword(password);
							currentCustomer = customerUtil.findUser(name);
							if(currentCustomer.getName()==" ")
								cout<<"ENTER VALID USERNAME"<<endl;
							}while(currentCustomer.getName()==" ");

							cout<<"CHOOSE OPERATIONS"<<endl;
							cout<<"1. BOOK TICKETS"<<endl;
							cout<<"2. DISPLAY THEATRE DETAILS"<<endl;
							cout<<"3. EXIT"<<endl;
							int selectAnyOperations;
							cin>>selectAnyOperations;
							CustomerUtil customerUtil1;
							//UserUtil userUtil;
							switch(selectAnyOperations) {
							case 1:
								int ticketMethods;
								cout<<"CHOOSE OPERATIONS";
								cout<<"1. BOOK TICKETS BY THEATRES"<<endl;
								cout<<"2. BOOK TICKETS BY MOVIE"<<endl;
								cout<<"3. BOOKING HISTORY"<<endl;
								cout<<"4. CANCEL TICKET"<<endl;
								cout<<"5. EXIT"<<endl;
								cin>> ticketMethods;
								switch(ticketMethods)
								{
								case 1:
									customerUtil1.bookTicketsByTheatres(currentCustomer);
									break;
								case 2 :
								    customerUtil1.bookTicketsByMovie(currentCustomer);
									break;
								case 3 :
									customerUtil.showBookingHistory(currentCustomer);
									break;
								case 4 :
								    customerUtil1.cancelTicket(currentCustomer);
									break;
                                case 5:
                                    break;
								}
								break;
							case 2:
								userUtil.displayTheatres(availableTheatres,totalTheatre);
								break;
							case 3 :
								break;
							}

							break;
						}
						case 2:
							customerUtil.registerDetails();
							break;
						case 3:
							break;
						}

					}while(selectedOperation != 3);
					break;
            }

        }
    }while(userType!=3);
}
