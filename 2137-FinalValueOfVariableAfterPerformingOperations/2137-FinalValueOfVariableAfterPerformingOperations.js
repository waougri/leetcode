// Last updated: 5/20/2026, 11:36:03 PM
/**
 * @param {string[]} operations
 * @return {number}
 */
 var finalValueAfterOperations = function(operations) {

    let x = 0;
    for(const element of operations){
        if(element==="++X" || element === "X++"){
            x+=1
        }
        else if(element==="--X" || element === "X--"){
            x--
        }
    }
    return x
};

