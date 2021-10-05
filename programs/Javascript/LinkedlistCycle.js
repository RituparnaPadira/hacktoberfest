//Given a linked list find if list has a cycle or not

const cycle = (head) => {
    let firstPointer = head;
    let secondPointer = head;

    while(firstPointer !== null && firstPointer.next !== null){
        firstPointer = firstPointer.next.next;
        secondPointer = secondPointer.next

        if(firstPointer === secondPointer){
            return true;
        }
    }
    return false;
}