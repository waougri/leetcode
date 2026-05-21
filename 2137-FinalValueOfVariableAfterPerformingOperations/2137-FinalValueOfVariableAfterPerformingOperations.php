// Last updated: 5/20/2026, 11:35:56 PM
<?php
class Solution{

    /**
     * @param String[] $operations
     * @return Integer
     */
    function finalValueAfterOperations($operations) {
        $x = 0;
        foreach ($operations as $op){
            if($op =="X++" || $op =="++X"){
                $x +=1;
            }
            elseif($op =="X--" || $op =="--X"){
                $x -=1;
            }
        }
        return $x;
    }
	/**
	 */
	
}
?>