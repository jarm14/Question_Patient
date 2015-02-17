#include <iostream>
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <conio.h>
//#include "question.h"

using namespace std;

class connexion{
	
	
	void show_error(unsigned int handletype, const SQLHANDLE& handle){
		SQLCHAR sqlstate[1024];
		SQLCHAR message[1024];
		if(SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlstate, NULL, message, 1024, NULL)){}
			//cout<<"Alerta: "<<message<<"\nSQLSTATE: "<<sqlstate<<endl;		
	}

public:

	int getCount(){
		
		int count;
		SQLHANDLE sqlenvhandle;    
		SQLHANDLE sqlconnectionhandle;
		SQLHANDLE sqlstatementhandle;
		SQLRETURN retcode;

		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle))
			goto FINISHED;

		if(SQL_SUCCESS!=SQLSetEnvAttr(sqlenvhandle,SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) 
			goto FINISHED;
    
		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle))
			goto FINISHED;

		SQLCHAR retconstring[1024];
		switch(SQLDriverConnect (sqlconnectionhandle, 
					NULL, 
					(SQLCHAR*)"Driver={SQL Server Native Client 10.0};Server=tcp:ogt4jiumex.database.windows.net,1433;Database=espe;Uid=espe@ogt4jiumex;Pwd={Admin112358.};Encrypt=yes;Connection Timeout=30;", 
					SQL_NTS, 
					retconstring, 
					1024, 
					NULL,
					SQL_DRIVER_NOPROMPT)){
			case SQL_SUCCESS_WITH_INFO:
				show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
				break;
			case SQL_INVALID_HANDLE:
			case SQL_ERROR:
				show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
				goto FINISHED;
			default:
				break;
		}
    
		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle))
			goto FINISHED;

		if(SQL_SUCCESS!=SQLExecDirect(sqlstatementhandle, (SQLCHAR*)"select count(*) from question", SQL_NTS)){
			show_error(SQL_HANDLE_STMT, sqlstatementhandle);
			goto FINISHED;
		}
		else{
			
			if(SQLFetch(sqlstatementhandle)==SQL_SUCCESS){//Fetch datos de base de datos
				SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &count, 0, NULL);
			
	
			}
		}

	FINISHED:
		SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle );
		SQLDisconnect(sqlconnectionhandle);
		SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
		SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

		return count;
	}

	int getCountPatient(){
		
		int count;
		SQLHANDLE sqlenvhandle;    
		SQLHANDLE sqlconnectionhandle;
		SQLHANDLE sqlstatementhandle;
		SQLRETURN retcode;

		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle))
			goto FINISHED;

		if(SQL_SUCCESS!=SQLSetEnvAttr(sqlenvhandle,SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) 
			goto FINISHED;
    
		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle))
			goto FINISHED;

		SQLCHAR retconstring[1024];
		switch(SQLDriverConnect (sqlconnectionhandle, 
					NULL, 
					(SQLCHAR*)"Driver={SQL Server Native Client 10.0};Server=tcp:ogt4jiumex.database.windows.net,1433;Database=espe;Uid=espe@ogt4jiumex;Pwd={Admin112358.};Encrypt=yes;Connection Timeout=30;", 
					SQL_NTS, 
					retconstring, 
					1024, 
					NULL,
					SQL_DRIVER_NOPROMPT)){
			case SQL_SUCCESS_WITH_INFO:
				show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
				break;
			case SQL_INVALID_HANDLE:
			case SQL_ERROR:
				show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
				goto FINISHED;
			default:
				break;
		}
    
		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle))
			goto FINISHED;

		if(SQL_SUCCESS!=SQLExecDirect(sqlstatementhandle, (SQLCHAR*)"select count(*) from patient", SQL_NTS)){
			show_error(SQL_HANDLE_STMT, sqlstatementhandle);
			goto FINISHED;
		}
		else{
			
			if(SQLFetch(sqlstatementhandle)==SQL_SUCCESS){//Fetch datos de base de datos
				SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &count, 0, NULL);
			
	
			}
		}

	FINISHED:
		SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle );
		SQLDisconnect(sqlconnectionhandle);
		SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
		SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);

		return count;
	}

	question *getQuestion(){
		int count;
		count=getCount();
		question *_question;
		question *_questions;
		_question= new question[count];
		SQLHANDLE sqlenvhandle;    
		SQLHANDLE sqlconnectionhandle;
		SQLHANDLE sqlstatementhandle;
		SQLRETURN retcode;

		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle))
			goto FINISHED;

		if(SQL_SUCCESS!=SQLSetEnvAttr(sqlenvhandle,SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) 
			goto FINISHED;
    
		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle))
			goto FINISHED;

		SQLCHAR retconstring[1024];
		switch(SQLDriverConnect (sqlconnectionhandle, 
					NULL, 
					(SQLCHAR*)"Driver={SQL Server Native Client 10.0};Server=tcp:ogt4jiumex.database.windows.net,1433;Database=espe;Uid=espe@ogt4jiumex;Pwd={Admin112358.};Encrypt=yes;Connection Timeout=30;", 
					SQL_NTS, 
					retconstring, 
					1024, 
					NULL,
					SQL_DRIVER_NOPROMPT)){
			case SQL_SUCCESS_WITH_INFO:
				show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
				break;
			case SQL_INVALID_HANDLE:
			case SQL_ERROR:
				show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
				goto FINISHED;
			default:
				break;
		}
    
		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle))
			goto FINISHED;

		if(SQL_SUCCESS!=SQLExecDirect(sqlstatementhandle, (SQLCHAR*)"select * from question", SQL_NTS)){
			show_error(SQL_HANDLE_STMT, sqlstatementhandle);
			goto FINISHED;
		}
		else{
			int i=0;//recorre el array de question
			int id_question;
			int id_doctor;
			int id_patient;
			
			while(SQLFetch(sqlstatementhandle)==SQL_SUCCESS){//Fetch datos de base de datos
				
				char date[18];
				char text[1024];
				char context[2048];
				char answer[2048]="";
				char comment[2048];

				SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &id_question, 0, NULL);
				SQLGetData(sqlstatementhandle, 2, SQL_C_ULONG, &id_doctor, 0, NULL);
				SQLGetData(sqlstatementhandle, 3, SQL_C_ULONG, &id_patient, 0, NULL);
				SQLGetData(sqlstatementhandle, 4, SQL_C_CHAR, date, 18, NULL);
				SQLGetData(sqlstatementhandle, 5, SQL_C_CHAR, text, 1024, NULL);
				SQLGetData(sqlstatementhandle, 6, SQL_C_CHAR, context, 2048, NULL);
				SQLGetData(sqlstatementhandle, 7, SQL_C_CHAR, answer, 2048, NULL);
				SQLGetData(sqlstatementhandle, 8, SQL_C_CHAR, comment, 2048, NULL);
				
				//Guardar datos en objeto
				_question[i].setIdQuestion(id_question);
				_question[i].setIdDoctor(id_doctor);
				_question[i].setIdPatient(id_patient);
				_question[i].setDate(date);
				_question[i].setText(text);
				_question[i].setContext(context);
				_question[i].setAnswer(answer);
				_question[i].setComment(comment);
				i++;
				
	
			}
		}

	FINISHED:
		SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle );
		SQLDisconnect(sqlconnectionhandle);
		SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
		SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);
		_questions=_question;
		return _questions;
	}

	patient *getPatient(){
	
		int count;
		count=getCountPatient();
		patient *_patient;
		patient *_patients;
		_patient= new patient[count];
		SQLHANDLE sqlenvhandle;    
		SQLHANDLE sqlconnectionhandle;
		SQLHANDLE sqlstatementhandle;
		SQLRETURN retcode;

		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle))
			goto FINISHED;

		if(SQL_SUCCESS!=SQLSetEnvAttr(sqlenvhandle,SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) 
			goto FINISHED;
    
		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle))
			goto FINISHED;

		SQLCHAR retconstring[1024];
		switch(SQLDriverConnect (sqlconnectionhandle, 
					NULL, 
					(SQLCHAR*)"Driver={SQL Server Native Client 10.0};Server=tcp:ogt4jiumex.database.windows.net,1433;Database=espe;Uid=espe@ogt4jiumex;Pwd={Admin112358.};Encrypt=yes;Connection Timeout=30;", 
					SQL_NTS, 
					retconstring, 
					1024, 
					NULL,
					SQL_DRIVER_NOPROMPT)){
			case SQL_SUCCESS_WITH_INFO:
				show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
				break;
			case SQL_INVALID_HANDLE:
			case SQL_ERROR:
				show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
				goto FINISHED;
			default:
				break;
		}
    
		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle))
			goto FINISHED;

		if(SQL_SUCCESS!=SQLExecDirect(sqlstatementhandle, (SQLCHAR*)"select * from patient", SQL_NTS)){
			show_error(SQL_HANDLE_STMT, sqlstatementhandle);
			goto FINISHED;
		}
		else{
			int i=0;//recorre el array de question
			int id_patient;
			
			while(SQLFetch(sqlstatementhandle)==SQL_SUCCESS){//Fetch datos de base de datos
				
				char name[512];
				char surName[512];
				char email[320];

				SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &id_patient, 0, NULL);
				SQLGetData(sqlstatementhandle, 2, SQL_C_CHAR, name, 512, NULL);
				SQLGetData(sqlstatementhandle, 3, SQL_C_CHAR, surName, 512, NULL);
				SQLGetData(sqlstatementhandle, 4, SQL_C_CHAR, email, 320, NULL);
				
				//Guardar datos en objeto
				_patient[i].setId(id_patient);
				_patient[i].setName(name);
				_patient[i].setSurName(surName);
				_patient[i].setEmail(email);
				
				i++;	
	
			}
		}

	FINISHED:
		SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle );
		SQLDisconnect(sqlconnectionhandle);
		SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
		SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);
		_patients=_patient;
		return _patients;
	}

	void newQuestion(question _question){
		
		//Data test
			/*	question _question;		
				////Guardar datos en objeto
				_question.setIdQuestion(3);
				_question.setIdDoctor(1);
				_question.setIdPatient(1);
				_question.setDate("2015-02-16 18:25:08");
				_question.setText("Is this a test?");
				_question.setContext("I am testing the application");
				//_question.setAnswer("");
				//_question.setComment("");*/
		char buffer[100] = {0};
		string idQuestion = itoa(_question.getIdQuestion(),buffer,10);
		string idDoctor = itoa(_question.getIdDoctor(),buffer,10);
		string idPatient = itoa(_question.getIdPatient(),buffer,10);
		string SQLStmt = "INSERT INTO question([id], [doctor_id], [patient_id], [date], [text], [context]) VALUES ('";
		SQLStmt += idQuestion; 
		SQLStmt += "','";
		SQLStmt += idDoctor;
		SQLStmt += "','";
		SQLStmt += idPatient;
		SQLStmt += "',convert(datetime2,'";
		SQLStmt += _question.getDate();
		SQLStmt += "',20),'";
		SQLStmt += _question.getText();
		SQLStmt += "','";
		SQLStmt += _question.getContext();
		SQLStmt += "')";

		SQLHANDLE sqlenvhandle;    
		SQLHANDLE sqlconnectionhandle;
		SQLHANDLE sqlstatementhandle;
		SQLRETURN retcode;

		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlenvhandle))
			goto FINISHED;

		if(SQL_SUCCESS!=SQLSetEnvAttr(sqlenvhandle,SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0)) 
			goto FINISHED;
    
		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_DBC, sqlenvhandle, &sqlconnectionhandle))
			goto FINISHED;

		SQLCHAR retconstring[1024];
		switch(SQLDriverConnect (sqlconnectionhandle, 
					NULL, 
					(SQLCHAR*)"Driver={SQL Server Native Client 10.0};Server=tcp:ogt4jiumex.database.windows.net,1433;Database=espe;Uid=espe@ogt4jiumex;Pwd={Admin112358.};Encrypt=yes;Connection Timeout=30;", 
					SQL_NTS, 
					retconstring, 
					1024, 
					NULL,
					SQL_DRIVER_NOPROMPT)){
			case SQL_SUCCESS_WITH_INFO:
				show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
				break;
			case SQL_INVALID_HANDLE:
			case SQL_ERROR:
				show_error(SQL_HANDLE_DBC, sqlconnectionhandle);
				goto FINISHED;
			default:
				break;
		}
    
		if(SQL_SUCCESS!=SQLAllocHandle(SQL_HANDLE_STMT, sqlconnectionhandle, &sqlstatementhandle))
			goto FINISHED;

		//Here
		if(SQL_SUCCESS!=SQLExecDirect(sqlstatementhandle, (SQLTCHAR *)SQLStmt.c_str(), SQL_NTS)){
			show_error(SQL_HANDLE_STMT, sqlstatementhandle);
			goto FINISHED;
		}
		
	FINISHED:
		SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle );
		SQLDisconnect(sqlconnectionhandle);
		SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
		SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);
	}


};