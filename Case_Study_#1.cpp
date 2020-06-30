#include<iostream>

using namespace std; 

class Registration{
	protected:
	int cnic,dob_d,dob_m,dob_y,total_marks,pass;    
 	bool isStudent;
 	float obtained_marks;
	string name,fname; 
	public:	
	Registration(){
		isStudent=false;
	}
			void Register()
		{
			cout<<"Enter your name :";
			cin>>name;
			cout<<"Enter your fater name :";
			cin>>fname;
			cout<<"Enter your CNIC No. without dashes i.e 3730116648887:";
			cin>>cnic;
			cout<<"Enter your DOB :\n";
			cout<<"Day :";
			cin>>dob_d;
			cout<<"Month :";
			cin>>dob_m;
			cout<<"Year :";
			cin>>dob_y;
			cout<<"Enter your password :";
			cin>>pass;
			cout<<"Enter your Just Bachelor Degree Marks :";
			cout<<"\nnEnter Obtained marks:";
			cin>>obtained_marks;
			cout<<"Enter Out of marks:";
			cin>>total_marks;						
		 }
		void admitStudent()
		{
			bool ret=false;			
			bool leapYear=false;
						
			float perc;
			perc=(this->obtained_marks/this->total_marks)*100;			
		  
		  if (dob_y % 4 == 0)
           {
              if (dob_y % 100 == 0)
               {
                 if (dob_y % 400 == 0)
                     leapYear=true;
                 else
                     leapYear=false;
                }
             else
                 leapYear=true;
            }
             else
                 leapYear=false;
                 
		if(perc>60&&leapYear)
		{
			cout<<"\nYou are admited as you have "<<perc<<"% and DOB is Leap Year";
		this->isStudent=true;
		}
		else{
			if(!leapYear)
	       cout<<"\nYour DOB is not Leap Year; you are not admited";
	       if(perc<60)
	       cout<<"\nYour Bachelor "<<perc<<"% is less than 60%; you are not admited";		
		   this->isStudent=false;	
		}	
					
	}
	
};  
class Faculty:public Registration
{  
   private: 
   float avg,Sem_marks;
   
    public:
    	 string grade;
    	Faculty()
		{
			grade="Papers not checked yet!";
		}
  
      void take_exam()
     {
   
       if(isStudent)
      {
      	int mark[6];
		  int sum=0;   	
   	 cout<<"\nEnter marks obtained in 6 subjects of 1st Semester:";
	for(int i=0; i<6; i++)
	{
		cout<<"\nSubject "<<i+1<<" marks : ";
		cin>>mark[i];
		sum=sum+mark[i];
	}
	Sem_marks=sum;
	avg=Sem_marks/6;
	if(avg>=85)
	{
		grade="A Grade";
	}
	else if(avg>=70 && avg<85)
	{
		grade="B Grade";
	}
	else if(avg>60 && avg<70)
	{
		grade="C Grade";
	}
	else
	{
	grade="F Grade";
	}   
  }else
   cout<<"\nStudent Not admitted yet!\n";
 }

	
};
class DirectorExam: public Faculty{	
	protected:
	string	report;	 
	public:		
		void result(){
			 if(isStudent)
      {
			string compare="Papers not checked yet!";
			if((this->grade.compare(compare))==0)
			cout<<"\n"<<compare<<endl;
			else
			{
				if((this->grade.compare("F Grade"))==0)
						report="\nYour Fail.";
				else
			           report="\nYour are passed with Grade '"+this->grade+"'. congrats\n";						
			cout<<"\nRport has been gernerated student can view by loging in to their account."<<endl;	
         } 
		} else
   cout<<"\nStudent Not admitted yet!\n";
   }
};
class Student:public DirectorExam
{ 	
	public:	
	void get_info(int userid,int password)
	{		
		if(userid==cnic && pass==password)
		{		
		 if(this->isStudent)
		 {
		 	cout<<"Your information is as follow:\n";
			cout<<"Your name is :"<<name;
			cout<<"\nYour father name is :"<<fname;
			cout<<"\nYour CNIC NO. is :"<<cnic;
			cout<<"\nYour Bachelor mark are :"<<this->obtained_marks;
			cout<<"\nYour DOB is :";
			cout<<"\nDay :"<<dob_d;
			cout<<"\nMonth :"<<dob_m;
			cout<<"\nYear :"<<dob_y;
			cout<<"\n\nYour 1st semester report is:\n"<<this->report<<endl;						
		}
		else{
			cout<<"You are not admited beacuse you did not met our admission policy";
		}
	  }
	  else
	  cout<<"\nIncorrect UserID/Password or not applied before.\n";
   }
	
};
void menu(){	  
	  cout<<"\nSelect the user mode\n";
      cout<<"1. Registrar\n";
      cout<<"2. Director Exams\n";
      cout<<"3. Faculty\n";
      cout<<"4. Student\n";
      cout<<"5. Exit\n";	
}

  int main()  
{  
        Student s;
    int choice=0;   
    do
	{
		menu();
		cout<<"Enter corresponding number :";
      cin>>choice;
      switch(choice)
	   {
		 case 1:
		 	char input;
		 	cout<<"\nDo you want to apply for admission. Y||N :" ;
		 	cin>>input;
		 	if(input=='y')
		 	{
			s.Register();
			s.admitStudent();						  
			}
		     else
				system("CLS");  
				break;
		 case 2:
		 	char input2;
		 	cout<<"\nDo you want to share the result report with student. Y||N :";
		 	cin>>input2;
		 	if(input2=='y')		 	
		 	   s.result();	
				else
				system("CLS");  		              
			break;
		 case 3:
		 	char input3;
		 	cout<<"\nDo you want to Exam of 1st semester. Y||N :";
		 	cin>>input3;
		 	if(input3=='y')		 	
		 	   s.take_exam();
		    else
				system("CLS");  	
			break;
		 case 4:
		 	char input4;		 	
				cout<<"\nIf you have applied before; you can check your status by loging in to your account:\n";
			    cout<<"\nDo you want to Login. Y||N";
		 	    cin>>input4;
		 	    if(input4=='y')
		  	  {
		 		int userid,pass;
		 		cout<<"\nEnter CNIC NO. you entered while applying for admission :";
		 		cin>>userid;
		 		cout<<"\nEnter password :";
		 		cin>>pass;
		 		s.get_info(userid,pass);
			   } 
		 	   else
				{				
		 	      cout<<"\nGoinng back to Main menu\n";	
		 	      break;
		            }		
			break;
		 case 5:
			cout<<"\nGOOD BYE!\n";
			break;
		 default:
			cout<<"\nPlease give appropriate input\n";
			break;    	
	    }
	}while(choice!=5);
   }
   
