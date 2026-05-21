// Last updated: 5/20/2026, 11:36:23 PM
class Solution {
    public String defangIPaddr(String address) {
       String defangedIp =  address.replace(".", "[.]");
        return defangedIp;
    }
}