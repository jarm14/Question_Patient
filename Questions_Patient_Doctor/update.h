#include <iostream>
#include <windows.h>
#include <sqltypes.h>
#include <sql.h>
#include <sqlext.h>
#include <conio.h>
//#include "question.h"

using namespace std;

class update{
	
	
	void show_error(unsigned int handletype, const SQLHANDLE& handle){
		SQLCHAR sqlstate[1024];
		SQLCHAR message[1024];
		if(SQL_SUCCESS == SQLGetDiagRec(handletype, handle, 1, sqlstate, NULL, message, 1024, NULL)){}
			cout<<"Alerta: "<<message<<"\nSQLSTATE: "<<sqlstate<<endl;
			//getch();
	}

public:

	void answerQuestion(/*question _question*/){
		
		//Data test
				question _question;		
				////Guardar datos en objeto
				_question.setIdQuestion(3);
				_question.setIdDoctor(1);
				_question.setIdPatient(1);
				_question.setDate("2015-02-16 18:25:08");
				_question.setText("Is this a test?");
				_question.setContext("I am testing the application");
				_question.setAnswer("This is an answer");
				_question.setComment("This is a comment");
		char buffer[100] = {0};
		string idQuestion = itoa(_question.getIdQuestion(),buffer,10);
		string SQLStmt = "UPDATE question SET answer='";
		SQLStmt += _question.getAnswer();
		SQLStmt += "',comment='";
		SQLStmt += _question.getComent();
		SQLStmt += "' WHERE id=";
		SQLStmt += idQuestion;

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