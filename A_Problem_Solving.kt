fun main() = repeat(readln().toInt()) {
    val n = readln().toInt() 
    val arr = readln().split(" ").map { it.toInt() }  
    
    if (n >= 2 && arr[n - 1] == arr[n - 2] + 1) {
        println(arr[n - 2]) 
    } else {
        println("Ambiguous")  
    }
}