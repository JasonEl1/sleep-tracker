// should save sleep time and wake time for better statistics

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

using namespace std;

array<float,2> get_time_diff(int sleep_hour,int sleep_min,int wake_hour,int wake_min){
    float hours;
    float mins;

    if(sleep_hour<=6){
        hours = wake_hour - sleep_hour;
    }
    else{
        hours = 12-sleep_hour + wake_hour;
    }

    if(wake_min < sleep_min){
        hours -= 1;
    }

    if(sleep_min != 0){
        mins = 60-sleep_min + wake_min;
    }
    else{
        mins = wake_min;
    }

    if(mins == 60){
        mins = 0;
    }
    else if(mins > 60){
        mins -= 60;
    }

    array<float,2> return_list = {hours,mins};
    return return_list;
}

float get_total_hours(float hours, float mins){
    float total_hours = hours + mins/60;
    return total_hours;
}

int main(int argc, char * argv[]){
    int sleep[2];
    int wake[2];
    cout << "When did you go to sleep?\n";
    cout << "Hour (PM or AM): ";
    cin >> sleep[0];
    cout << "Minutes: ";
    cin >> sleep[1];
    cout << "\n";
    cout << "When did you wake up?\n";
    cout << "Hour (AM): ";
    cin >> wake[0];
    cout << "Minutes: ";
    cin >> wake[1];

    array<float,2> slept_time = get_time_diff(sleep[0],sleep[1],wake[0],wake[1]);

    stringstream time_summary;
    time_summary << slept_time[0] << " Hours, " << slept_time[1] << " Minutes slept.";

    cout << time_summary.str() << endl;

    float total_hours = get_total_hours(slept_time[0], slept_time[1]);


    time_t unix_timestamp;
    time(&unix_timestamp);
    struct tm *timeinfo = localtime(&unix_timestamp);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);

    string pwd = argv[0];
    pwd = pwd.substr(0,pwd.length()-14);
    string file_path = pwd + "/sleep_data.csv";

    ofstream file(file_path,ios_base::app);
    stringstream text_out;

    text_out << buffer << "," << round(total_hours*10)/10;
    file << text_out.str() << endl;
    file.close();

    stringstream confirmation_message;
    confirmation_message << "Added data to " << file_path;

    cout << confirmation_message.str() << endl;

    return 0;
}
