//part 1

var fs = require('fs');
var NFA = JSON.parse(fs.readFileSync('nfa.json', 'utf8'));
console.log(NFA)


//example of NFA
/*[
    {
        "id":0,
        "isEnd":false,
        "paths": [
            {
                "id":1,
                "data":"a"
            }
        ]
    },
    {
        "id":1,
        "isEnd":false,
        "paths": [
            {
                "id":2,
                "data":"ε"
            }
        ]
    },
    {
        "id":2,
        "isEnd":false,
        "paths": [
            {
                "id":3,
                "data":"ε"
            },
            {
                "id":13,
                "data":"ε"
            }
        ]
    },
    {
        "id":3,
        "isEnd":false,
        "paths": [
            {
                "id":4,
                "data":"ε"
            },
            {
                "id":8,
                "data":"ε"
            }
        ]
    },
    {
        "id":4,
        "isEnd":false,
        "paths": [
            {
                "id":5,
                "data":"c"
            }
        ]
    },
    {
        "id":5,
        "isEnd":false,
        "paths": [
            {
                "id":6,
                "data":"o"
            }
        ]
    },
    {
        "id":6,
        "isEnd":false,
        "paths": [
            {
                "id":7,
                "data":"w"
            }
        ]
    },
    {
        "id":7,
        "isEnd":false,
        "paths": [
            {
                "id":12,
                "data":"ε"
            }
        ]
    },
    {
        "id":8,
        "isEnd":false,
        "paths": [
            {
                "id":9,
                "data":"c"
            }
        ]
    },
    {
        "id":9,
        "isEnd":false,
        "paths": [
            {
                "id":10,
                "data":"a"
            }
        ]
    },
    {
        "id":10,
        "isEnd":false,
        "paths": [
            {
                "id":11,
                "data":"t"
            }
        ]
    },
    {
        "id":11,
        "isEnd":false,
        "paths": [
            {
                "id":12,
                "data":"ε"
            }
        ]
    },
    {
        "id":12,
        "isEnd":false,
        "paths": [
            {
                "id":13,
                "data":"ε"
            }
        ]
    },
    {
        "id":13,
        "isEnd":true,
        "paths": [
            {
                "id":2,
                "data":"ε"
            }
        ]
    }
]
*/


//find epsilon closure of a state NON recursive
function epsilonClosure(stateId, NFA) {
    var closure = [];
    closure.push(stateId);
    var state = NFA[stateId];
    var paths = state.paths;
    for (var i = 0; i < paths.length; i++) {
        if (paths[i].data == "ε") {
            if (closure.indexOf(paths[i].id) == -1){
                closure.push(paths[i].id);
            }
            var state2 = NFA[paths[i].id];
            var paths2 = state2.paths;
            for (var j = 0; j < paths2.length; j++) {
                if (paths2[j].data == "ε") {
                    if (closure.indexOf(paths2[j].id) == -1){
                        closure.push(paths2[j].id);
                    }
                }
            }
        }
            
    }
    return closure;
}

console.log(epsilonClosure(2, NFA));