//part 1

var fs = require('fs');
var NFA = JSON.parse(fs.readFileSync('nfa.json', 'utf8'));
console.log("part 1:")
console.log(NFA)


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
console.log("part 2:")
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
                            // console.log("added path: "+nextPath.id)
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


        // console.log("DFA["+i+"]");
        // console.log(DFA[i]);
        i++;
        
        //add paths to DFA, unless already present
        DFA[i-1].paths.forEach(function(path) {
            if (DFA.indexOf(NFA[path.id]) == -1) {
                DFA.push(NFA[path.id]);
            }
        });
    }

    // console.log(DFA[i].paths);

    //print dfa
    console.log("part 3:")
    for (var i = 0; i < DFA.length; i++) {
        console.log(DFA[i]);
    }
}



convertNFAtoDFA(NFA);