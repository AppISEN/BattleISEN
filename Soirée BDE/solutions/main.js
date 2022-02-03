/*****************************************************
*                                                    *
*              Solution par Allan Cueff              *
*                                                    *
*****************************************************/

/*******
 * Read input from STDIN
 * Use: console.log()  to output your result.
 * ***/

 var readline = require('readline');
 var rl = readline.createInterface({
   input: process.stdin,
   output: process.stdout,
   terminal: false
 });
 var input = [];
 
 rl.on('line', function(value){ //Read input values
     input.push(value);
 })
 //Call ContestResponse when all inputs are red
 rl.on("close", ContestResponse); 
 
 function ContestResponse(){
     N = parseInt(input[1], 10);
     K = parseInt(input[2], 10);
     let inputList = [];
     for(line of input){
         inputList.push(line.split(' '));
     }
     let ecarts = [];
     for(let i = 0; i<N; i++){
         ecarts.push(0);
     }
     for(let i = 0; i < inputList[0].length; i++){ //for each event
         let myRate = inputList[0][i];
         for(let j = 3; j < N + 3; j++) { //for each friend
             ecarts[j-3] += Math.abs(inputList[j][i]-myRate);//somme des écarts
         }
     }
     let bestFriendsList = [];
     for(let j = 0; j < K; j++){
         let bestFriendId = -1;
         let bestFriendEcart = Infinity;
         for(let i = 0; i < ecarts.length; i++){ //selection des meilleurs amis
             if(ecarts[i]<bestFriendEcart && !bestFriendsList.includes(i)) {
                 bestFriendId = i;
                 bestFriendEcart = ecarts[i];
             }
         }
         bestFriendsList.push(bestFriendId);
     }
     let rate = 0;
     for(bestFriendId of bestFriendsList){
         rate += parseInt(inputList[bestFriendId + 3][inputList[0].length],10);
     }
     console.log(Math.trunc(rate/K));
 }