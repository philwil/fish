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

int g_debug = 0;

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
    raining = 0;
    on_ticks = 0;
    off_ticks = 0;
    ticks = 0;
    pumpOnTime = 5000;
    pumpOffTime = 5000;
    wPRate = 0.003;
    
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
    cout << " Pump :" << ticks<<": state "<< pstate
      << " water level :"
      ;
    cout << wHeight;
    cout << " Current : " << pumpcur;
    cout << " on_ticks left  " << (on_ticks - ticks);
    cout << " off_ticks left  " << (off_ticks - ticks);
    cout << endl;
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
  
  void startRain( double rate) {
    raining = 1;
    wRate = rate;
  }
  
  void stopRain() {
    raining = 0;
  }
  
  
  int getPump () {
    return pumpon;
  }
  
  void pumpOn() {
    if(pumpon == 0) {
      on_ticks = ticks + pumpOnTime;
      if(g_debug) {
	cout<<" Turned on pump at "<<ticks<<" level "<< wHeight<< endl;
      }
      pumpon = 1;
      pumpcur = 2.0;
    }
  }
  
  void pumpOff() {
    if(pumpon == 1) {
      off_ticks = ticks + pumpOffTime;
      if(g_debug) {
	cout<<" Turned off pump at "<<ticks<<" level "<< wHeight<< endl;
      }
      pumpon = 0;
    }
  }
  
  void runTick(){
    ticks++;
    if(raining) {
      wHeight += wRate;
    }
    if (pumpon) {
      wHeight -= wPRate;
      if(wHeight < 0.2) pumpcur = 0.0;
      // check on_time
      if (ticks > on_ticks) {
	if (wHeight > 0.5 ) {
	  pumpOnTime += 1000;
	}
	pumpOff();
      }
      if  (pumpcur < 0.1) {
	pumpOff();
      }
    } else {
      if (ticks > off_ticks) {
	if (wHeight > 0.5 ) {
	  pumpOn();
	}
      }
    }
  }
  
  int raining;
  double wRate;
  double wPRate;
  double wHeight;
  int pumpon;
  double pumpcur;
  long int on_ticks;
  long int off_ticks;
  long int ticks;
  long int pumpOnTime;
  long int pumpOffTime;
  
};

Pump *pump;
#if 1


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


int stopTick = 1;
pthread_t tickTh;

void *tickThread( void *data)
{
  Pump * p = (Pump *) data;
  cout << " tick thread running" << endl;
  while (! stopTick) {
    poll(NULL, 0, 1);
    p->runTick();
  }
  cout << " tick thread stopping" << endl;
  
  pthread_exit(NULL);
}

int runTickThread(void)
{
  if (stopTick == 1) {
    stopTick = 0;
    pthread_create(&tickTh, NULL, tickThread, (void *)pump);
    
  } else {
    stopTick = 1;
    pthread_join(tickTh, NULL);
  }
}



int main_help (void) {
  cout<<"(s)how  -- show current objects "<<endl;
  cout<<"(w)rite -- write current objects to file"<<endl;
  cout<<"(a)dd   -- add water to pump"<<endl;
  cout<<"(r)ead  -- read  objects from file"<<endl;
  cout<<"(d)ebug -- turn on / off debug"<<endl;
  cout<<"(3)rstart -- start rain"<<endl;
  cout<<"(4)rstop  -- stop rain"<<endl;
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
	}else if ((action == "debug") 
	    || (action == "d")) {
	  if(g_debug) {
	    cout << "Turned off debug" << endl;
	    g_debug = 0;
	  } else {
	    cout << "Turned on debug" << endl;
	    g_debug = 1;
	  }
	  //pump->showPump();
	}else if ((action == "show") 
		  || (action == "s")) {
	  //nl.
	  pump->showPump();
	}else if ((action == "rstart") 
		  || (action == "3")) {
	  cout << " enter rate " << endl;
	  double rate;
	  cin >> rate;
	  pump->startRain(rate);
	}else if ((action == "rstop") 
		  || (action == "4")) {
	  pump->stopRain();
	  
	}else if ((action == "add")
		  || (action == "a")) {
	  cout<<"enter water level"<<endl;
	  double ps;
	  cin>>ps;
	  pump->addWater(ps);

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

#endif
//int ma
int main() {
  pump = new Pump();
  runTickThread();

  //int rc;
  //string val;
  //NumberList nl;
  main_loop(NULL);
  runTickThread();

return 0;

}
