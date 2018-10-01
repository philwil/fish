// A small example program using SQLite with C++

#include <iostream>
#include <sqlite3.h>

// g++ -o db1 db1.cpp -lsqlite3
using namespace std;
static int callback(void *data, int argc, char **argv, char **azColName)
{
  int i;
  int rnum = *(int *) data;
  cout << " Row number ["<< rnum <<"]" << endl; 
  if(data) *(int *)data = *(int *)data+1;
  for(i=0; i<argc; i++)
    {
      cout<< "arg [" << i<< "] " <<azColName[i]<<" = " << (argv[i] ? argv[i] : "NULL")<<"\n";
    }
  cout<<"\n";
  return 0;
}



int main()
{
  const int STATEMENTS = 8;
  sqlite3 *db;
  char *zErrMsg = 0;
  const char *pSQL[STATEMENTS];
  int rc;
  int row;

  rc = sqlite3_open("db1.db", &db);
  if( rc )
    {
      cout<<"Can't open database: "<<sqlite3_errmsg(db)<<"\n";
    }
  else
    {
      cout<<"Open database successfully\n\n";
    }

  pSQL[0] = "create table myTable (FirstName varchar(30), LastName varchar(30), Age smallint, Hometown varchar(30), Job varchar(30))";

  pSQL[1] = "insert into myTable (FirstName, LastName, Age, Hometown, Job) values ('Peter', 'Griffin', 41, 'Quahog', 'Brewery')";

  pSQL[2] = "insert into myTable (FirstName, LastName, Age, Hometown, Job) values ('Lois', 'Griffin', 40, 'Newport', 'Piano Teacher')";

  pSQL[3] = "insert into myTable (FirstName, LastName, Age, Hometown, Job) values ('Joseph', 'Swanson', 39, 'Quahog', 'Police Officer')";

  pSQL[4] = "insert into myTable (FirstName, LastName, Age, Hometown, Job) values ('Glenn', 'Quagmire', 41, 'Quahog', 'Pilot')";

  pSQL[5] = "select * from myTable";
  
  pSQL[6] = "delete from myTable"; 

  pSQL[7] = "drop table myTable";
  row = 0;
  for(int i = 0; i < STATEMENTS; i++)
    {
      cout << " Sql running [" << pSQL[i] << "]" << endl;
      rc = sqlite3_exec(db, pSQL[i], callback, &row, &zErrMsg);
      if( rc!=SQLITE_OK )
	{
	  cout<<"SQL error: "<<sqlite3_errmsg(db)<<"\n";
	  sqlite3_free(zErrMsg);
	  break;
	}
    }
  
  sqlite3_close(db);
  return 0;

}
