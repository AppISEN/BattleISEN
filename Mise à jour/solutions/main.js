//Code issue d'une épreuve de BattleDev

//***************************************************************
//*
//*
//* SOLUTION BY richie3366
//*
//*
//******************************************************************

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
	//implements your code here using input array
	var fSize = input[0]*1
	var nCultivables = 0
	
	var grille = []
	
	input.slice(1).forEach(function(e) {
	    var lineArr = []
	    var cols = e.split('')
	    
	    cols.forEach(function(c) {
	        lineArr.push(c)
	    })
	    
	    grille.push(lineArr)
	})
	
	grille.forEach(function(line, x) {
	    line.forEach(function(cell, y) {
	        if(cell === 'X') {
	            for(var i = -1; i <= 1; i++) {
	                for(var j = -1; j <= 1; j++) {
	                    if(i === 0 & j === 0) continue
	                    if(x + i < 0 || y + j < 0 || x + i >= fSize || y + j >= fSize) continue
	                    
	                    if(grille[x + i][y + j] === '.') {
	                        grille[x + i][y + j] = 'O'
	                        nCultivables++
	                    }
	                }
	            }
	        }
	    });
	})
	
	console.log(nCultivables)
}