For this project I was asked to analyze cargo that was to be theoretically shipped to Zimbabwe 
and was allowed to choose the conditions of the qualified cargo

-This combination of programs is designed to analyze batches of cargo that contained
 food cans, blankets and medical kits
-Each batch is first sorted out by whether it's contents can fit within 90% of the volume of the crate (for leg room)
 This assumes predetermined dimensions for the crate and the supplies, although this can easily be adjusted
-Then for the batches that remain, the one with the highest food count is selected and its contents are printed 

How to use program:
1. Load the C++ program, and type in the file that you want to analyze (must be in the form seen in Sample-Batch-Data.txt)
   
   Sample-Batch-Data.txt format:
   The first column represents the batch number, the second represents number of canned food
   the third represents number of blankets and the fourth represents number of medical kits
   
2. The C++ program will then create a file that contains all of the qualified batches 
3. First a Cost file must be created in excel, stating the price of each item horizontally. This will end up being a row with three columns.
4. Load the Matlab program and it will load the Cost excel file and the file created by C++ and print out the ideal batch
5. The costs file can be changed to three different costs if that is desired