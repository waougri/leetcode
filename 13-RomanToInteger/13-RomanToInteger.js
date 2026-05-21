// Last updated: 5/20/2026, 11:37:56 PM
/**
 * @param {string} s
 * @return {number}
 */
 var romanToInt = function(s) {
  var dict = {
    'I':1,
    'V':5,
    'X':10,
    'L':50,
    'C':100,
    'D':500,
    'M':1000
  };
  
  s = s.replace("IV","IIII").replace("IX","VIIII");
  s = s.replace("XL","XXXX").replace("XC","LXXXX");
  s = s.replace("CD","CCCC").replace("CM","DCCCC");
  
  var result = 0;

  for (var i = 0; i < s.length; i++) {
      result+=dict[s[i]];
  }
  return result;
};
console.log(romanToInt("MCMXCIV"))