/* pump test code

 */


#include <iostream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <poll.h>


//struct timespec now;
//gm_get_timestamp(&now);
using namespace std;

#define PI 3.141

double sinTable[100];
// GET a-b
int64_t ts_diff_ns(struct timespec *tA,struct timespec *tB)
{
    int64_t diff = 0;
    int64_t tA_total_nsec = 0;
    int64_t tB_total_nsec = 0;

    tA_total_nsec = (((int64_t)tA->tv_sec) * (int64_t)1000000000) + (int64_t)tA->tv_nsec;
    tB_total_nsec = (((int64_t)tB->tv_sec) * (int64_t)1000000000) + (int64_t)tB->tv_nsec;
    diff = (tA_total_nsec - tB_total_nsec);

    return diff;
}

int64_t ts_diff_ms(struct timespec *tA,struct timespec *tB)
{
    return ts_diff_ns(tA, tB) / (int64_t)1000000;
}

void ts_add_ms(struct timespec *tA, long int ms)
{
    uint64_t accum_nsec = 0;
    uint64_t accum_sec = 0;

    accum_nsec = (ms * (int64_t)1000000) + (int64_t)tA->tv_nsec;

    while (accum_nsec >= (int64_t)1000000000)
    {
        accum_sec += 1;
        accum_nsec -= (int64_t)1000000000;
    }

    tA->tv_sec +=  (time_t)accum_sec;
    tA->tv_nsec =  (long)accum_nsec;
}

void get_timestamp( struct timespec *tts , int delms )
{
  clock_gettime(CLOCK_MONOTONIC, tts);
  ts_add_ms(tts, delms);
  
}
//is now > ts 
int check_timestamp(struct timespec *tts)
{
  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC, &now);
  if (ts_diff_ms(tts, &now) > 0) return 1;
  return 0;
  
}

class Pump {
public:
  Pump(){
    wHeight = 0.0;
    pumpon = 0;
    pumpcur = 0.0;
    
  }

  ~Pump(){
  }
  
  int showPump(void) {
    string pstate;
    if(pumpon) {
      pstate = " Running";
    } else {
      pstate = "Stopped";
    }
    cout << " Pump :" << pstate
      << " water level :"
      ;
    cout << wHeight;
    cout<< " Current : " << pumpcur
	<< endl;
    return 0;
  }
  
  int addWater ( double level) {
    wHeight += level;
  }
  
  int checkWater () {
    if(wHeight> 0.2) return 1 ;
    return 0;
  }
  double checkCurrent () {
    return pumpcur ;
  }
  // attempt to set the pump on or off
  int setPump (int on) {
    // if off_time not passed refuse to turn on
    if (( on ==  1) && (check_timestamp(&off_time)) && ( pumpon == 0)) {
	if (check_timestamp(&off_time)) {
	  pumpon = on;
	  // max on time
	  get_timestamp(&on_time, 5000);
	} else {
	  cout << " Pump off not timed out, waiting" << endl;
	}
	if((on == 0) && (pumpon == 1)){
	  // min off time
	  get_timestamp(&off_time, 5000);
	}
      }
      //pumpon = on;
    return 0;
  }
  int getPump () {
    return pumpon;
  }
  
  int runPump(double seconds) {
    // if running too long turn off
    if(pumpon && check_timestamp(&on_time)) {
      cout << " Pump on time out, turn it off" << endl;
      setPump(0);
    }
    while (seconds > 0.0) {
      seconds -= 0.1;
      if (pumpon) {
	wHeight -= 0.1;
      }
      if (wHeight < 0.0 ) {
	wHeight = 0.0;
      }
    
      if (wHeight > 0.1 ) {
	pumpcur = 2.0;
      } else {
	pumpcur = 0.0;
      }
    }
  }
    
  double wHeight;
  int pumpon;
  double pumpcur;
  struct timespec on_time;
  struct timespec off_time;
};

Pump *pump;

int fillTable( int num)
{
  for (int i = 0 ; i < num; i++) {
    sinTable[i] = sin( (2.0 * PI * i)/100.0);
  }
}

int writeFile(string fname)
{
  cout << " nothing to write"  << endl;
  return 0;
}

int readFile(string fName)
{
  
  fName += ".txt";
  fstream input(fName.c_str());
  cout << " running readFile [" << fName<<"]"<< endl ;
  string line;
  int row = 0;
  int idx = 0;
  
  while (getline (input, line)) {
    row++;
    cout <<" row :"<< row <<" data [" << line<<"]" << endl;
    
    idx = 0;
    size_t pos = 0;
	  
    pos = line.find('B');
    if (pos != string::npos){
      //Number*n = new Number();
      //    n->setName("Barn");
      //    n->setX(pos+1);
      //    n->setY(row);
      //    insertNumber (n);
      //    Barn = n;
    }

  }
  return 0;
}



int showList(void)
{
  int num = 100;
  fillTable(num);
  int i ;
  int val;
  for (i = 0 ; i < num; i++) {
    val = 40 + sinTable[i] * 40 ;
    for (int j = 0 ; j < val; j++) {   
      cout<<"#";
    }
    cout << endl;
  }
  return 0;
}

int stopRain = 1;
pthread_t rainTh;

void *rainThread( void *data)
{
  Pump * p = (Pump *) data;
  cout << " rain thread running" << endl;
  while (! stopRain) {
    poll(NULL, 0, 100);
    p->addWater(0.1);
  }
  cout << " rain thread stopping" << endl;

  pthread_exit(NULL);
}

int runRainThread(void)
{
  if (stopRain == 1) {
    stopRain = 0;
    pthread_create(&rainTh, NULL, rainThread, (void *)pump);
    
  } else {
    stopRain = 1;
    pthread_join(rainTh, NULL);
  }
}

int stopPump = 1;
pthread_t pumpTh;

void *pumpThread( void *data)
{
  Pump * p = (Pump *) data;
  cout << "pump thread running" << endl;
  while (! stopPump) {
    poll(NULL, 0, 50);
    if (p->getPump() == 0) {
      
      if (p->checkWater()) {
	p->setPump(1);
      }
    } else {
      if(p->checkCurrent() < 1) {
	p->setPump(0);
	
	//p->setOffTime()
      }
      p->runPump(0.050);
    }
  }
  cout << " pump thread stopping" << endl;

  pthread_exit(NULL);
}

int runPumpThread(void)
{
  if (stopPump == 1) {
    stopPump = 0;
    pthread_create(&pumpTh, NULL, pumpThread, (void *)pump);
    
  } else {
    stopPump = 1;
    pthread_join(pumpTh, NULL);
  }
}

int main_help (void) {
  cout<<"(s)how  -- show current objects "<<endl;
  cout<<"(w)rite -- write current objects to file"<<endl;
  cout<<"(a)dd   -- add water to pump"<<endl;
  cout<<"(r)ead  -- read  objects from file"<<endl;
  cout<<"(t)urn  -- turn on / off pump"<<endl;
  cout<<"(d)ebug -- turn on / off debug"<<endl;
  cout<<"(1)rain -- turn on/off rain thread"<<endl;
  cout<<"(2)pump -- turn on/off pump thread"<<endl;
  cout<<"(q)uit  -- quit"<<endl;
  return 0;
}

int main_loop(void *nl) {

    string action;
    string fName;

    while (1) {

        cout<<"What would you like to do? (use help)"<<endl;
        cin>>action;

        if ((action == "help") 
	    || (action == "h")) {
	  //nl.
	  main_help();
	}else if ((action == "show") 
	    || (action == "s")) {
	  //nl.
	  pump->showPump();
	}else if ((action == "rain") 
	    || (action == "1")) {
	  //nl.
	  runRainThread();
	}else if ((action == "pump") 
	    || (action == "2")) {
	  //nl.
	  runPumpThread();
	}else if ((action == "add")
		  || (action == "a")) {
	  cout<<"enter water level"<<endl;
	  double ps;
	  cin>>ps;
	  pump->addWater(ps);
	}
	else if ((action == "prun") 
		  || (action == "p")) {
	  cout<<"enter seconds"<<endl;
	  
	  double ps;
	  cin >> ps;
	  pump->runPump(ps);

	}else if ((action == "turn") 
	    || (action == "t")) {
	  cout<<"Enter on/off"<<endl;
	  string ps;
	  cin>>ps;
	  if( ps == "on" ) {
	    pump->setPump(1);
	  } else {
	    pump->setPump(0);
	  }

        }else if ((action == "write")
		  || (action == "w")) {

	  cout<<"Enter file name"<<endl;
	  cin>>fName;
	  //nl.
	  writeFile(fName);
            //writeToFile(fName, nl);
        }else if ((action == "read") 
		  || (action == "r")) {

	  cout<<"Enter file name"<<endl;
	  cin>>fName;
	  //nl.
	  readFile(fName);
	  //Path = findDist(nl, Barn, Lake, Rock);
        }else if ((action == "quit")
		  || (action == "q")) {
	  
	  return 0;
        }
    }

    return 0;
}


//int ma
int main() {
  pump = new Pump();
  
  //int rc;
  //string val;
  //NumberList nl;
    main_loop(NULL);

return 0;

}
