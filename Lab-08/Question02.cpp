/*Cricket fans, get ready for some coding action! Imagine the ICC is developing a high-tech system
to analyze a batsman's total runs in a match. To make this happen, let's create two C++ classes—
Runs and BallsFaced—to store the number of runs scored and the number of balls faced by a
batsman, respectively. But since these two classes are as secretive as a team's match strategy,
we’ll introduce them to a mutual friend function called calculateStrikeRate(), which will access
their private data and calculate the player's strike rate using the formula:
Strike Rate = (Runs / Balls Faced) × 100
Your task is to write a C++ program where calculateStrikeRate() takes values from both classes
(e.g., a batsman scores 85 runs off 60 balls) and computes the strike rate.*/

#include<iostream>
using namespace std;

class BallsFaced;
class Runs{
    int tRuns;
    friend double calculateStrikeRate(Runs, BallsFaced);
public:
    Runs(int r): tRuns(r){}
};

class BallsFaced{
    int tBalls;
    friend double calculateStrikeRate(Runs, BallsFaced);
public:
    BallsFaced(int bf): tBalls(bf){}
};

double calculateStrikeRate(Runs runs_obj, BallsFaced balls_obj){
    double strikeRate;
    strikeRate = ((double)runs_obj.tRuns / balls_obj.tBalls) * 100;
    return strikeRate;
}

int main(){
    BallsFaced b(60);
    Runs run(85);
    cout << "Strike Rate: " << calculateStrikeRate(run, b);
    return 0;
}