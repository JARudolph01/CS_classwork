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
    
    var nodesUnderConsideration = [];

    nodesUnderConsideration.push(stateId);
    
    while (nodesUnderConsideration.length > 0) {
        NFA[nodesUnderConsideration[0]].paths.forEach(function(path) {
            if(path.data == 'ε') {
                // if not already in nodesUnderConsideration
                if(nodesUnderConsideration.indexOf(path.id) == -1 && closure.indexOf(path.id) == -1) {
                    nodesUnderConsideration.push(path.id);
                    closure.push(path.id);
                    // console.log(path.id);
                }
            }
        });
        nodesUnderConsideration.shift();
    }
    
    return closure;
}

console.log(epsilonClosure(1, NFA));