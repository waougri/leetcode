// Last updated: 5/20/2026, 11:36:38 PM
function search(nums: number[], target: number): number {
    let lo = 0;
    let hi = nums.length;

    do
    {
        const m = Math.floor(lo + (hi - lo) / 2);
        const v = nums[m];

        if(target === nums[m])
        {
            return m;
        }
        else if (target > nums[m])
        {
            lo = m + 1;
        } 
        else 
        {
            hi = m;
        }

    }while(lo < hi);
    return -1;
};