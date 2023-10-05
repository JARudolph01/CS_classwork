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

//part 2
//find epsilon closure of a state
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

console.log(epsilonClosure(13, NFA));



//part 3
//convert the NFA to DFA by skipping over epsilon transitions

function arraysEqual(a1,a2) {
    /* WARNING: arrays must not contain {objects} or behavior may be undefined */
    return JSON.stringify(a1)==JSON.stringify(a2);
}

function convertNFAtoDFA(nfa) {
    var DFA = [];
    DFA.push(nfa[1]);

    var i = 0;
    while (i<DFA.length) {

        //while paths contains epsilon transitions
        oldpaths = []

        while ( !arraysEqual(DFA[i].paths,oldpaths)) {
            //copy value of DFA[0].paths, not refrence
            oldpaths = []
            DFA[i].paths.forEach(function(path) {
                oldpaths.push(path);
            });

            // console.log(oldpaths==DFA[0].paths)

            DFA[i].paths.forEach(function(path) {
                if(path.data == 'ε') {
                    // add the paths of the next node, if not already present
                    NFA[path.id].paths.forEach(function(nextPath) {

                        if (DFA[i].paths.indexOf(nextPath) == -1) {
                            console.log("added path: "+nextPath.id)
                            DFA[i].paths.push(nextPath);
                        }
                    });
                }       
            });  
        }

        //now we can remove all epsilon transitions
        DFA[i].paths.forEach(function(path) {
            if(path.data == 'ε') {
                DFA[i].paths = DFA[i].paths.filter(function(e) { return e.data != 'ε' })
            }
        });


        console.log("DFA["+i+"]");
        console.log(DFA[i]);
        i++;
        
        //add paths to DFA, unless already present
        DFA[i-1].paths.forEach(function(path) {
            if (DFA.indexOf(NFA[path.id]) == -1) {
                DFA.push(NFA[path.id]);
            }
        });
    }

    // console.log(DFA[i].paths);
}



convertNFAtoDFA(NFA);