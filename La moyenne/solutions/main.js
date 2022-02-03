/*****************************************************
*                                                    *
*              Solution par Allan Cueff              *
*                                                    *
*****************************************************/

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
    let result = 0;
    let len = input[0];
    for(let i=1; i<=len; i++){
        result+=parseFloat(input[i],10);
    }
    console.log(result/parseFloat(len, 10).toFixed(2));
}