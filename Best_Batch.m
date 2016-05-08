function [ array ] = Best_Batch( batches, food )
%Takes in a matrix and returns the row that has 
%the most amount of canned food

count = size(batches,1); %Stores the number of rows in the matrix

for i=1:count; %loops through each row in the matrix
    if batches(i, 3) == food; %if the amount of food in that row is equal to the max value
        array = batches(i, :); %then return that row as the variable array
    end
end
return