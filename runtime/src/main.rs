use ewasm::{Execute, RootRuntime};

fn main() {
    let code = include_bytes!("/Users/jonny/projects/consensys/pegasys/ee/anmlee/build/random-forest.wasm").to_vec();
    println!("foo");
    let mut runtime = RootRuntime::new(&code, &[], [0u8; 32]);
    println!("bar");
    let _post = runtime.execute();
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::mem::transmute;
    fn u32_to_value(n: u32) -> [u8; 32] {
        let mut buf = [0u32; 8];
        buf[0] = n;
        unsafe { transmute::<[u32; 8], [u8; 32]>(buf) }
    }
    
    fn build_value(n: &u32) -> Vec<u8> {
        u32_to_value(*n).to_vec()
    }
    #[test]
    fn test() {
        let asm = vec![1u32, 2, 3, 4, 5, 6]
                    .iter()
                    .flat_map(build_value)
                    .collect::<Vec<u8>>();
        let mut runtime = RootRuntime::new(&asm, &[], [0u8; 32]);
        
        runtime.set_logger(|b| {
            println!("{}", b);
        });

        let _ = runtime.execute();
    }
}