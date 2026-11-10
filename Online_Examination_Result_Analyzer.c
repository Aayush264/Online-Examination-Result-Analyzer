#include <stdio.h>
#include <string.h>

#define Total 5

void viewAllResults(char StudentNames[Total][20], int StudentRollno[Total], int TotalMarks[Total], float Percentage[Total])
{
    
    for(int i = 0; i < Total; i++)
    {
        printf("[%d]\n", i + 1);

        printf("Name => %s\n", StudentNames[i]);
    
        printf("Roll no. => %d\n", StudentRollno[i]);

        printf("Total marks obtained (out of 500) => %d\n", TotalMarks[i]);

        printf("Percentage obtained => %.3f\n", Percentage[i]);

        printf("Rank => %d\n", i + 1);

    
        if (Percentage[i] >= 33)
            printf("\nResult: PASS\n");
    
        else
            printf("\nResult: FAIL\n");


    
        if (Percentage[i] < 33)
            printf("\nGrade: F\n\n");


        else if (Percentage[i] >= 90)
            printf("\nGrade: A+\n\n");

    
        else if (Percentage[i] >= 80)
            printf("\nGrade: A\n\n");
    
    
        else if (Percentage[i] >= 70)
            printf("\nGrade: B\n\n");

    
        else if (Percentage[i] >= 60)
            printf("\nGrade: C\n\n");
    
    
        else if (Percentage[i] >= 50)
            printf("\nGrade: D\n\n");

    
        else
            printf("\nGrade: E\n\n");

    }
}



int main()
{
    printf("\n~~~~~~ Online Examination Result Analyzer ~~~~~~\n");  
    
    char StudentNames[Total][20];

    int StudentRollno[Total];

    char Subject[5][10] = {"Maths", "Physics", "Chemistry", "English", "Computer"};

    int Marks[Total][5];  //2D array


    //Data Entry

    for(int i = 0; i < Total; i++)
    {
        printf("\n\nEnter name of student (%d) => ", i+1);

        scanf("%s", StudentNames[i]);


        int duplicate;

        do
        {
            duplicate = 0;

            printf("\nEnter roll no. of student (%d) => ", i+1);
            scanf("%d", &StudentRollno[i]);

            // Check previous students' roll numbers

            for(int j = 0; j < i; j++)
            {
                if(StudentRollno[i] == StudentRollno[j])
                {
                    printf("\nThis roll number already exists! Enter another roll number.\n");

                    duplicate = 1;
                    break;
                }
            }

            if(StudentRollno[i] <= 0)
            {
                printf("\nRoll number must be positive!\n");
                
                duplicate = 1;
                continue;
            }

        } while(duplicate == 1);



        for(int j = 0; j < 5; j++)
        {
            int validMarks;

            do
            {
                printf("\nEnter marks in %s => ", Subject[j]);
                scanf("%d", &Marks[i][j]);

                validMarks = 1;

                if(Marks[i][j] < 0 || Marks[i][j] > 100)
                {
                    printf("\nInvalid marks! Enter marks between 0 and 100.\n");
                    validMarks = 0;
                }

            } while(validMarks == 0);
        }
    }


    //Result Calculation

    int TotalMarks[Total];

    for(int i = 0; i < Total; i++)
    {
        TotalMarks[i] = 0;

        for(int j = 0; j < 5; j++)
        {
            TotalMarks[i] = TotalMarks[i] + Marks[i][j];
        }
    }

    float Percentage[Total];

    for(int i = 0; i < Total; i++)
    {
        Percentage[i] = (TotalMarks[i] / 500.0) * 100;
    }


    
    // BUBBLE SORT (RANKING)

    int temp = 0;

    float temp_P = 0;

    for (int i = 0; i < Total - 1; i++)
    {
        for (int j = 0; j < Total - i - 1; j++)
        {
            if (TotalMarks[j] < TotalMarks[j + 1])
            {
                // Swap total marks

                temp = TotalMarks[j];

                TotalMarks[j] = TotalMarks[j + 1];

                TotalMarks[j + 1] = temp;



                // Swap roll numbers

                temp = StudentRollno[j];

                StudentRollno[j] = StudentRollno[j + 1];

                StudentRollno[j + 1] = temp;



                // Swap percentages

                temp_P = Percentage[j];

                Percentage[j] = Percentage[j + 1];

                Percentage[j + 1] = temp_P;


                
                // Swap student names

                char tempName[20];

                strcpy(tempName, StudentNames[j]);

                strcpy(StudentNames[j], StudentNames[j + 1]);

                strcpy(StudentNames[j + 1], tempName);



                // Swap subject marks

                for (int k = 0; k < 5; k++)
                {
                    temp = Marks[j][k];

                    Marks[j][k] = Marks[j + 1][k];

                    Marks[j + 1][k] = temp;
                }
            }
        }
    }


    // MAIN MENU

    int choice;

    do
    {
        printf("\n\n===== MAIN MENU =====\n");
        printf("1. View All Results and Ranking\n");
        printf("2. Search Student Result\n");
        printf("3. Analysis and Ranking\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            // OPTION 1: VIEW ALL RESULTS

            case 1:

                printf("\n===== STUDENT RESULTS =====\n\n");

                viewAllResults(StudentNames, StudentRollno, TotalMarks, Percentage);

                break;


            // OPTION 2: SEARCH STUDENT RESULT

            case 2:
            {
                int Rollno;

                printf("\n\nEnter the Roll no. of student for its result => ");
                scanf("%d", &Rollno);

                int found = 0;

                for(int i = 0; i < Total; i++)
                {
                    if(Rollno == StudentRollno[i])
                    {
                        printf("\n===== STUDENT RESULTS =====\n\n");

                        printf("Name => %s\n", StudentNames[i]);
                        printf("Roll no. => %d\n", StudentRollno[i]);
                        printf("Total marks => %d\n", TotalMarks[i]);
                        printf("Percentage => %.3f\n", Percentage[i]);

                        if (Percentage[i] >= 33)
                            printf("\nResult: PASS\n");
                    
                        else
                            printf("\nResult: FAIL\n");

                    
                        if (Percentage[i] < 33)
                            printf("\nGrade: F");


                        else if (Percentage[i] >= 90)
                            printf("\nGrade: A+");

                    
                        else if (Percentage[i] >= 80)
                            printf("\nGrade: A");
                    
                    
                        else if (Percentage[i] >= 70)
                            printf("\nGrade: B");

                    
                        else if (Percentage[i] >= 60)
                            printf("\nGrade: C");
                    
                    
                        else if (Percentage[i] >= 50)
                            printf("\nGrade: D");

                    
                        else
                            printf("\nGrade: E");

                        
                        found = 1;
                        break;
                    }
                    
                }

                    if(found == 0)
                        printf("\n\nStudent not found!\n");

                    break;
            }


            // OPTION 3: ANALYSIS AND RANKING

            case 3:
            {
                int PassCount = 0;
                int FailCount = 0;
                int ClassMarks = 0;

                float ClassAverage;


                // Calculate class statistics

                for(int i = 0; i < Total; i++)
                {
                    ClassMarks = ClassMarks + TotalMarks[i];

                    if(Percentage[i] >= 33)
                        PassCount++;
                    else
                        FailCount++;
                }

                ClassAverage = (float)ClassMarks / Total;


                // Display class analysis

                printf("\n\n===== CLASS ANALYSIS =====\n");

                printf("\nTotal Students => %d", Total);

                printf("\nClass Average => %.2f%%", ClassAverage / 5);

                printf("\nStudents Passed => %d", PassCount);

                printf("\nStudents Failed => %d", FailCount);


                // Highest Scorer

                printf("\n\n===== HIGHEST SCORER =====\n");

                for(int i = 0; i < Total; i++)
                {
                    if(TotalMarks[i] == TotalMarks[0])
                    {
                        printf("\nName => %s\n", StudentNames[i]);
                        printf("Roll No. => %d\n", StudentRollno[i]);
                        printf("Total Marks => %d\n", TotalMarks[i]);
                        printf("Percentage => %.2f%%\n", Percentage[i]);

                        if (Percentage[i] >= 33)
                            printf("\nResult: PASS\n");
                    
                        else
                            printf("\nResult: FAIL\n");
                    }
                }


                // Lowest Scorer

                printf("\n===== LOWEST SCORER =====\n");

                for(int i = 0; i < Total; i++)
                {
                    if(TotalMarks[i] == TotalMarks[Total - 1])
                    {
                        printf("\nName => %s\n", StudentNames[i]);
                        printf("Roll No. => %d\n", StudentRollno[i]);
                        printf("Total Marks => %d\n", TotalMarks[i]);
                        printf("Percentage => %.2f%%\n", Percentage[i]);

                        if (Percentage[i] >= 33)
                            printf("\nResult: PASS\n");
                    
                        else
                            printf("\nResult: FAIL\n");
                    }
                }

                break;
            }
            

            // EXIT

            case 0:

                break;


            default:

                printf("\n\nInvalid choice!\n");

        }

    } while (choice != 0);

    return 0;
}