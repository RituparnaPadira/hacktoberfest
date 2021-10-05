//replace spaces on strings with "%20" 
//eg: Input- hello world
//Output- hello%20world

//given string and length of the string
function urlify(str, len){
    let s = " ";
    let totalSpaces = str.length - len;
    let frontSpaces = 0;
    let flag = false;

    for(let i=0; i<str.length; i++){
        if(flag === false){
            if(str[i] === " ") frontSpaces++;
            else flag = true;
        }
        if(flag === true && i<str.length - (totalSpaces - frontSpaces)){
            if(str[i] === " ") s+='%20';
            else s += str[i];
        }
    }
    return s;
}