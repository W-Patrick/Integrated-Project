load Data_For_Matlab.txt; %Loads the text file created by C++ Program
batches = Data_For_Matlab; %Assigns the matrix from the text file to a variable named batches
input = xlsread('Cost.xlsx'); %Loads the excel file with the costs and assigns the matrix to the variable, input
costs = [0]; 

%Rearranges the matrix obtained from the excel file as a vertical matrix 
%with zero being the value in the first row
for i=input;
   costs = [costs ; i]; 
end

results = batches * costs; %Returns a matrix with the costs of each batch
max_food = max(batches(:, 2)); %Returns the max value of food found in the initial matrix
batches_and_cost = [results, batches]; %Creates a new matrix, appending the costs and the initial matrix

best = Best_Batch(batches_and_cost, max_food); %Returns the row that contains the most food

fprintf('\nThe ideal batch is batch %-2.0f\n',best(2)) %Prints out the ideal batch number
fprintf('This batch contains %-2.0f canned food\n',best(3)) %Prints out number of canned food in that batch
fprintf('%-2.0f blankets, %-2.0f medical kits,\n', best(4), best(5)) %Prints out number of blankets and med kits in that batch
fprintf('and will cost %-2.0f dollars.\n\n', best(1)) %Prints out how much this batch will cost






    