#include <iostream>
#include <string>
using namespace std;
int main()
{
    double age, height, weight,BMI,BMR_W=0,BMR_M=0,PAL=0,TDI=0,BFP,muscle_mass,muscle_percrntage,temp,LBM;
    char  gender;
    string ask_PAL;
    cout << "                 welcome in our Health Assessment System      " << endl;
    cout << "Enter your age : " << endl;
    cin >> age;
    cout << "Enter your Gender : (F/M) " << endl;
    cin >> gender;
    while (gender != 'm' && gender != 'f')
    {
        cout << "invalid data! , enter again \n ";
        cin >> gender;
    }
    cout << "How active you are ? \n Sedentary \n Lightly_active \n Moderately_active \n Very_active \n Super_active \n";
    cin >> ask_PAL;
    while (ask_PAL != "Super_active" && ask_PAL != "Sedentary" && ask_PAL != "Lightly_active" && ask_PAL != "Moderately_active" && ask_PAL != "Very_active")
    {
        cout << "invalid data , enter the correct choice of them \n";
        cin >> ask_PAL;
    }
    if (ask_PAL == "Sedentary")
        PAL = 1.2;
    else if (ask_PAL == "Lightly_active")
        PAL = 1.375;
    else if (ask_PAL == "Moderately_active")
        PAL = 1.55;
    else if (ask_PAL == "Very_active")
        PAL = 1.725;
    else if (ask_PAL == "Super_active")
        PAL = 1.9;
    cout << "Enter your height : (cm) " << endl;
    cin >> height;
    cout << "Enter your weight : (kg) " << endl;
    cin >> weight;
    temp = height;
    temp /= 100;
    BMI = (weight) / (temp * temp);
    BMR_W = 10 * weight + 6.25 * height - 5 * age - 161;
    BMR_M = 10 * weight + 6.25 * height - 5 * age + 5;
    if (gender == 'f')
    {
        TDI = BMR_W * PAL;
        BFP = 1.2 * BMI + 0.23 * age - 5.4;
        LBM = 0.252 * weight + 0.473 * height - 48.3;

    }
    else
    {
        TDI = BMR_M * PAL;
        BFP = 1.2 * BMI + 0.23 * age - 16.2;
        LBM = 0.407 * weight + 0.267 * height - 19.2;
    }
   
    
    
    muscle_percrntage = (LBM / weight) * 100;
    if (BMI < 18.5)
        cout << " \nunfortunately you are Underweighted \n you have to eat aroud "<< 500+TDI <<"  kcal/day. \n come back to check your progress after approxmiatly 3 weeks \n GOOD BYE << OUR FIGHTER >> \n \n ";
    else if (BMI < 24.9)
        cout << " \nGOOD JOB \n you are Normal weighted \n maintain your weight, your daily calorie intake should be around " << TDI << " kcal/day.\n <<OUR MONSTER>> \n";
    else if (BMI < 30)
        cout << "\n unfortunately you are Overweighted \n you have to eat around " << TDI - 500 << " kcal/day.\n come back to check your progress after approxmiatly 3 weeks \n GOOD BYE <<OUR FIGHTER>> \n \n ";
    else
        cout << "\n unfortunately you have Obesity  \n  !!GO TO DOCTOR URGENTALLY!! \n you should eat around " << TDI - 700 << " kcal/day.\n  come back to check your progress after approxmiatly 8 weeks \n GOOD BYE <<OUR FIGHTER>> \n  \n";
    if (gender == 'f')
    {
        cout << " \nYour Basal Metabolic Rate (BMR) --> " << BMR_W << " kcal/day.\n \n";
        cout << " your BMI-Based Body Fat Percentage (BFP) --> " << BFP<<" %" << endl;

    }
    else
    {
        cout << " \n Your Basal Metabolic Rate (BMR) is: " << BMR_M << " kcal/day.\n \n";
        cout << " your BMI-Based Body Fat Percentage (BFP) --> " << BFP<<" %"<<endl;
    }
    cout << "\n your muscle mass --> " << LBM <<" (kg) "<< endl;
    cout << "\n your muscles percentage --> " << muscle_percrntage <<" %" <<endl;
    cout << "\n Your Total Daily Intake (TDI), adjusted for activity level, is : " << TDI << " kcal/day.\n";
    return 0;
}
