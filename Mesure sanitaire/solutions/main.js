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
     input.shift();
     input.shift();
 
     let nbCovid = 0;
     input.forEach(function(classe){
         let covid = 0;
         classe.split(" ").forEach(function(eleve){
             if(parseInt(eleve) == 1){
                 covid++;
             }
         });
         if(covid/classe.split(" ").length < 0.9){
             nbCovid++;
         }
     });
    
     console.log(nbCovid);
 }