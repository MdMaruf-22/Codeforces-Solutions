fun main() = repeat(readln().toInt()) {
    val s = readln().toInt()

    val mcnugget = 5 * 3 - 5 - 3
    var ans = 0

    // Used chicken mcnugget theorem :)
    if (s > mcnugget) {
        ans = 0
    } else if (s == 1 || s == 4 || s == 7) {
        ans = 1
    } else if (s == 2) {
        ans = 2
    }

    println(ans)
}
