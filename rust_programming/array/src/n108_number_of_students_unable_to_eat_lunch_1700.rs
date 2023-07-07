
pub fn count_students(students: Vec<i32>, sandwiches: Vec<i32>) -> i32
{
    if students.is_empty() ||
       sandwiches.is_empty() ||
       students.len() != sandwiches.len() {
        return 0;
    }

    let len:usize = students.len();
    let mut stu_dup:Vec<i32> = students.clone();
    let mut sand_index:usize = 0;

    for _i in 0..len * 2 {
        if stu_dup[0] == sandwiches[sand_index] {
            sand_index += 1;
        } else {
            stu_dup.push(stu_dup[0]);
        }
        stu_dup.remove(0);
    }

    return stu_dup.len() as i32;
}


#[cfg(test)]
mod tests {

    use super::*;
    #[test]
    fn test_demo() {
        let students = vec![1,1,0,0];
        let sandwiches = vec![0,1,0,1];
        let ret = count_students(students, sandwiches);
        assert_eq!(ret, 0);

        let students = vec![1,1,1,0,0,1];
        let sandwiches = vec![1,0,0,0,1,1];
        let ret = count_students(students, sandwiches);
        assert_eq!(ret, 3);
    }
}