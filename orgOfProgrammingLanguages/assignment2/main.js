var fs = require('fs');

var obj = JSON.parse(fs.readFileSync('nfa.json', 'utf8'));

console.log(obj)