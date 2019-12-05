use ewasm::{Execute, RootRuntime};

fn main() {
    fn asm() -> Vec<u8> {
        let ret = include_bytes!(concat!(
            env!("OUT_DIR"),"/../../../../../../build/random-forest.wasm"));
        ret.to_vec()
    }
    let code = asm();
    let mut runtime = RootRuntime::new(&code, &[], [0u8; 32]);
    runtime.set_logger(|b| {
        print!("{}", b);
    });
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