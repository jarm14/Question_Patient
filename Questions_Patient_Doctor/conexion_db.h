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
			cout<<"Alerta: "<<message<<"\nSQLSTATE: "<<sqlstate<<endl;		
	}

public:

	question *getQuestion(){

		question *_question;
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
			int id_question;
			int id_doctor;
			int id_patient;
			char date[18];
			char text[1024];
			char context[2048];
			char answer[2048];
			char comment[2048];
			int cont=0;
			while(SQLFetch(sqlstatementhandle)==SQL_SUCCESS){//Fetch datos de base de datos
				SQLGetData(sqlstatementhandle, 1, SQL_C_ULONG, &id_question, 0, NULL);
				SQLGetData(sqlstatementhandle, 2, SQL_C_ULONG, &id_doctor, 0, NULL);
				SQLGetData(sqlstatementhandle, 3, SQL_C_ULONG, &id_patient, 0, NULL);
				SQLGetData(sqlstatementhandle, 4, SQL_C_CHAR, date, 18, NULL);
				SQLGetData(sqlstatementhandle, 5, SQL_C_CHAR, text, 1024, NULL);
				SQLGetData(sqlstatementhandle, 6, SQL_C_CHAR, context, 2048, NULL);
				SQLGetData(sqlstatementhandle, 7, SQL_C_CHAR, answer, 2048, NULL);
				SQLGetData(sqlstatementhandle, 8, SQL_C_CHAR, comment, 2048, NULL);
				cont++;
				
			}

			_question= new question[cont];
			int i=0;
			
			if(SQL_SUCCESS!=SQLExecDirect(sqlstatementhandle, (SQLCHAR*)"select * from question", SQL_NTS)){
				show_error(SQL_HANDLE_STMT, sqlstatementhandle);
				goto FINISHED;
			}
			else{
				
				while(SQLFetch(sqlstatementhandle)==SQL_SUCCESS){//Fetch datos de base de datos
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
	
				}
			}
		
		}

	FINISHED:
		SQLFreeHandle(SQL_HANDLE_STMT, sqlstatementhandle );
		SQLDisconnect(sqlconnectionhandle);
		SQLFreeHandle(SQL_HANDLE_DBC, sqlconnectionhandle);
		SQLFreeHandle(SQL_HANDLE_ENV, sqlenvhandle);
		return _question;
	}
};