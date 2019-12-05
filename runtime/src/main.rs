use std::time::{Duration, Instant};
use ewasm::{Execute, RootRuntime};

fn main() {
    let mut runtime = load(true);
    let _post = runtime.execute();
}

fn load(logging: bool) -> RootRuntime<'static>  {
    fn asm() -> Vec<u8> {
        let ret = include_bytes!(concat!(
            env!("OUT_DIR"),"/../../../../../../build/random-forest.wasm"));
        ret.to_vec()
    }
    let code = asm();
    let mut runtime = RootRuntime::new(&code, &[], [0u8; 32]);
    if logging {
        runtime.set_logger(|b| {
            print!("{}", b);
        });
    }
    return runtime;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        let mut runtime = load(false);
        let beginTime = Instant::now();
        let _post = runtime.execute();
        let endTime = Instant::now();
        println!("\nExecution Time: {:?}\n", endTime.duration_since(beginTime));

    }
}