
ulong _main(uint param_1,ulong param_2)

{
  uint uVar1;
  int  uVar2;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = stack_base;
  uVar4 = stack_base - 0x20;
  stack_base = uVar4;

  // 5246544 or uVar1 or stack_base is the place where the params get written to.
  // probably the stack pointer base
  store(stack_base-4, 0)

  // store param1 to uvar-8
  stove(stack_base-8, param1)

  // stores param2 to uvar-12, which is an offset of 4 bytes, which makes sense
  store(stack_base - 0xc, param2 & 0xffffffff) // i think this AND(&) is unecessary

  uint argc = load(stack_base-8)

  // param1 must be >= 3
  // else it returns 1 as a failure case
  if (argc < 3) {
    store(stack_base-4, 1)
  }
  else { 

    GONZALEZ_8() ; // xor the chunk in memory at 0x670
    // ['N', ' ', 'G', 'o', 'n', 'z', 'a', 'l', 'e', 'z']

    // this behavior reminds me of argv.
    // TEST: what if i set param2 to the memloc they get written to?
    uVar2 = *(param2 + 4);
    uVar3 = *(param2 + 8);

    uVar2 = _FUNCTION_9( uvar2, uvar3 )

    // store return of f9
    store( stack_base-0x10, uVar2 )
    // given 5246528, 4 returned -2

    uVar2 = load(stack_base-0x10)
    store(uVar4, uVar2)

    _FUNCTION_51(0x441, uVar4);
    // given 5246512, returned 
    // uhhh didn't lol
    // oh it's just printf lol

    // uVar4 <- [uVar1 - 0x10]
    uVar4 = load(stack_base-0x10)
    store(stack_base-4, uVar4)
  }

  return load(stack_base-4)
}

// converts a chunk of memory at 0x670 to 'N Gonzalez'
// by xor'ing it with code-encoded key
void GONZALEZ_8(void)
{
  uint uVar1;
  char cVar2;
  
  // loads a byte, xors it with a key. does this for 10 bytes.
  // oh! must be the 1640 memory segment!

  // ['N', ' ', 'G', 'o', 'n', 'z', 'a', 'l', 'e', 'z']

  cVar2 = _i32_load8_u(*_Z_envZ_memory,0x670);
  _i32_store8(*_Z_envZ_memory,0x670,(ulong)((int)cVar2 ^ 0xde));
  cVar2 = _i32_load8_u(*_Z_envZ_memory,0x671);
  _i32_store8(*_Z_envZ_memory,0x671,(ulong)((int)cVar2 ^ 0x49));
  cVar2 = _i32_load8_u(*_Z_envZ_memory,0x672);
  _i32_store8(*_Z_envZ_memory,0x672,(ulong)((int)cVar2 ^ 5));
  cVar2 = _i32_load8_u(*_Z_envZ_memory,0x673);
  _i32_store8(*_Z_envZ_memory,0x673,(ulong)((int)cVar2 ^ 0x58));
  cVar2 = _i32_load8_u(*_Z_envZ_memory,0x674);
  _i32_store8(*_Z_envZ_memory,0x674,(ulong)((int)cVar2 ^ 0x7d));
  cVar2 = _i32_load8_u(*_Z_envZ_memory,0x675);
  _i32_store8(*_Z_envZ_memory,0x675,(ulong)((int)cVar2 ^ 0x72));
  cVar2 = _i32_load8_u(*_Z_envZ_memory,0x676);
  _i32_store8(*_Z_envZ_memory,0x676,(ulong)((int)cVar2 ^ 0x71));
  cVar2 = _i32_load8_u(*_Z_envZ_memory,0x677);
  _i32_store8(*_Z_envZ_memory,0x677,(ulong)((int)cVar2 ^ 0x65));
  cVar2 = _i32_load8_u(*_Z_envZ_memory,0x678);
  _i32_store8(*_Z_envZ_memory,0x678,(ulong)((int)cVar2 ^ 0x6d));
  cVar2 = _i32_load8_u(*_Z_envZ_memory,0x679);
  _i32_store8(*_Z_envZ_memory,0x679,(ulong)((int)cVar2 ^ 0x7d));
  *_wasm_rt_call_stack_depth = *_wasm_rt_call_stack_depth - 1;
  return;
}


// inputs: argv[1], argv[2]
// possible return values: -1, -2, or the good outcome
ulong _FUNCTION_9(uint param_1,uint param_2)
{
  uint stack1;
  char cVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  bool bVar8;
  
  stack1 = stack_base;
  uVar7 = stack_base - 0x30;

  stack_base = uVar7;
  store(stack1 - 8,param_1);
  store(stack1 - 0xc, param_2);
  store(stack1 - 0x10, 0xff);

  arg1p = [stack1-8]

  len_arg1 = _getLength(arg1p); // first arg

  // what's the third arg here? a memory location or a 0xff
  // a memloc containing 0xff
  uVar7 = _FUNCTION_7( arg1p, len_arg1, (stack1 - 0x10));
  // input: banana, 6. what do we return?
  // 0. unclear what this function does.

  store(stack1 - 0x14, uVar7);
  uVar7 = load(stack1 - 0xc); // second arg
  uVar4 = _getLength( [stack1-0xc] );
  uVar7 = _FUNCTION_7((ulong)uVar7,(ulong)uVar4,(ulong)(stack1 - 0x10));
  // this one (input: Gonzalez, 8) returns a pointer, to that 712 blob in memory, for things
  // of length 8.

  store(stack1 - 0x18, uVar7);
  uVar7 = load(stack1 - 0x18);

  // note 0x670
  // does something to param2, the second thing to be pushed.
  uVar7 = _FUNCTION_11(uVar7,0x670,10);
  // 0, 0x670, 10 -> -78

  // called with 5246712 containing 'N Gonzalez', returns decimal 60
  // even so with something dumb like banana

  // how can we cause function11 to return 0?
  // what's in the memory address uVar7 or 5246712
  // weird shit. 138, 40, 162, 138,40,162
  // n gonzalez as decimal [78, 32, 71, 111, 110, 122, 97, 108, 101, 122]

  // test: try changing username to see if it's a username check
  // some.
  // test: password

  store(stack1 - 0x1c,uVar7);
  iVar5 = load(stack1 - 0x1c);

  // this checks uVar7
  if (iVar5 == 0) {
    store(stack1 - 0x20,1);
    store(stack1 - 0x24,10);
    uVar7 = load(stack1 - 0x14);
    uVar7 = _getLength((ulong)uVar7);
    store(stack1 - 0x28, uVar7);
    uVar7 = load(stack1 - 0x18);
    uVar7 = _getLength((ulong)uVar7);
    store(stack1 - 0x2c, uVar7);
    while( true ) {
      uVar7 = load(stack1 - 0x24);
      uVar4 = load(stack1 - 0x28);
      bVar8 = false;
      if (uVar7 < uVar4) {
        uVar7 = load(stack1 - 0x24);
        uVar4 = load(stack1 - 0x2c);
        bVar8 = uVar7 < uVar4;
      }
      if (!bVar8) break;
      iVar5 = load(stack1 - 0x14);
      iVar6 = load(stack1 - 0x24);
      cVar2 = load8_u(iVar6 + iVar5);
      iVar5 = load(stack1 - 0x18);
      iVar6 = load(stack1 - 0x24);
      cVar3 = load8_u(iVar6 + iVar5);
      if (cVar2 != cVar3) break;
      iVar5 = load(stack1 - 0x24);
      store(stack1 - 0x24, (iVar5 + 1));
      iVar5 = load(stack1 - 0x20);
      store(stack1 - 0x20, (iVar5 + 1));
    }
    
    iVar5 = load(stack1 - 0x24);
    iVar6 = load(stack1 - 0x28);

    // ooh here's a CMP!!! maps to f9:296 in wasm
    if (iVar5 == iVar6) {
      // this is a fail!
      [stack1-4] = -1
      // but if i can find the equivalent of it and ask manticore to get me to this space
      // then i'll be good to go
    }
    else {
      // this must be the success case.
    	[stack1-4] = [stack1-0x20]
    }
  }
  else {
    // this is also a fail!
    [stack1-4] = -2
  }

  uVar7 = load(stack1 - 4);
  stack_base = stack1;
  return uVar7;
}




ulong _FUNCTION_51(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = stack_base;
  uVar2 = stack_base - 0x10;
  stack_base = uVar2;
  store(uVar1 - 4, param_2);
  uVar2 = _i32_load(*_Z_envZ_memory,0x668);
  uVar2 = _FUNCTION_34((ulong)uVar2,(ulong)param_1,(ulong)param_2);
  stack_base = uVar1;
  return (ulong)uVar2;
}


// takes a pointer to one of the arguments
// only used in f9 afaict
// called on both arguments
// does no stores, meaning it simply returns some value

// input: banana, output: 6
// LENGTH CHECK
ulong _getLength(uint param_1)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint local_1c;
  uint local_14;
  uint local_10;
  
  uVar1 = param_1;
  if ((param_1 & 3) == 0) {
    do {
      local_10 = uVar1;
      local_14 = local_10;
      uVar2 = load(local_10);
      uVar1 = local_10 + 4;
    } while ((uVar2 + 0xfefefeff & (uVar2 ^ 0xffffffff) & 0x80808080) == 0);
    if ((uVar2 & 0xff) == 0) {
      local_1c = local_10 - param_1;
      return local_1c;
    }
    do {
      iVar3 = _i32_load8_u(*_Z_envZ_memory,(ulong)(local_14 + 1));
      local_14 = local_14 + 1;
      local_10 = local_14;
    } while (iVar3 != 0);
  }
  else {
    iVar3 = _i32_load8_u(*_Z_envZ_memory,(ulong)param_1);
    local_10 = param_1;
    if (iVar3 == 0) {
      local_1c = 0;
      return local_1c;
    }
    do {
      local_10 = local_10 + 1;
      uVar1 = local_10;
      if ((local_10 & 3) == 0) goto LAB_00018993;
      iVar3 = load8_u(local_10);
    } while (iVar3 != 0);
  }
  local_1c = local_10 - param_1;
  return local_1c;
}


//                     pointer to mem  0x670      10
ulong _FUNCTION_11(uint param_1,uint param_2,int param_3)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint local_24;
  uint local_18;
  
  else {
    local_18 = 0;

    uVar2 = load8_u(param_1);

    while (
    (((uVar1 = local_18, uVar2 != 0 && // can't be null, else we'll quit instantly
       (
        uVar3 = load8_u(param_2),
        uVar1 = uVar2,
        (uVar2 & 0xff) == uVar3
       ) ) && (
        param_3 = param_3 + -1, // for 10 iterations
        param_3 != 0
      ) ) && (uVar3 != 0))
    )
    {
      param_2 = param_2 + 1; // increment pointer to N Gonzalez 0x670 in mem
      uVar2 = load8_u(param_1 + 1); // load it
      param_1 = param_1 + 1; // incr pointer to input mem at 5246712
    } // endwhile

    local_18 = uVar1;
    iVar4 = load8_u(param_2);
    local_24 = (local_18 & 0xff) - iVar4; // we generally expect this to be 0.
  }
  return local_24;
}



// looks like f7 is the hairy beast
ulong _FUNCTION_7(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  void *pvVar7;
  uint uVar8;
  
  uVar1 = stack_base;
  uVar8 = stack_base - 0x130;
  stack_base = uVar8;
  store(uVar1 - 8, param_1);
  store(uVar1 - 0xc, param_2);
  store(uVar1 - 0x10, param_3);
  store(Var8,0;
  _f42((ulong)(uVar1 - 0x110),0x80,0x100);
  store(uVar1 - 0x124,0);
  while (uVar2 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x124)), uVar2 < 0x40) {
    uVar2 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x124));
    iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x124));
    uVar3 = _i32_load8_u(*_Z_envZ_memory,(ulong)(iVar4 + 0x400));
    store8((uVar3 & 0xff  ),(ulong)uVar2);
    iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x124));
    store(uVar1 - 0x124, (iVar4 + 1));
  }
  store8(uVar1 - 0xd3,0);
  store(uVar1 - 0x128,0);
  store(uVar1 - 0x124,0);
  while( true ) {
    uVar2 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x124));
    uVar3 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0xc));
    if (uVar3 <= uVar2) break;
    iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 8));
    iVar6 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x124));
    uVar2 = _i32_load8_u(*_Z_envZ_memory,(ulong)(uint)(iVar6 + iVar4));
    uVar2 = _i32_load8_u(*_Z_envZ_memory,(ulong)((uVar2 & 0xff) + (uVar1 - 0x110)));
    if ((uVar2 & 0xff) != 0x80) {
      iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x128));
      store(uVar1 - 0x128, (iVar4 + 1));
    }
    iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x124));
    store(uVar1 - 0x124, (iVar4 + 1));
  }
  iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x128));
  if ((iVar4 == 0) || (uVar2 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x128)), (uVar2 & 3) != 0))
  {
    store(uVar1 - 4,0);
  }
  else {
    uVar2 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x128));
    store(uVar1 - 300, ((uVar2 >> 2) * 3));
    uVar2 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 300));
    pvVar7 = _malloc((ulong)uVar2);
    store(uVar1 - 0x114, pvVar7 & 0xffffffff);
    store(uVar1 - 0x118, pvVar7 & 0xffffffff);
    iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x114));
    if (iVar4 == 0) {
      store(uVar1 - 4,0);
    }
    else {
      store(uVar1 - 0x128,0);
      store(uVar1 - 0x124,0);
      while( true ) {
        uVar2 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x124));
        uVar3 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0xc));
        if (uVar3 <= uVar2) break;
        iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 8));
        iVar6 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x124));
        uVar2 = _i32_load8_u(*_Z_envZ_memory,(ulong)(uint)(iVar6 + iVar4));
        uVar2 = _i32_load8_u(*_Z_envZ_memory,(ulong)((uVar2 & 0xff) + (uVar1 - 0x110)));
        store8(uVar1 - 0x11d, uVar2);
        uVar2 = _i32_load8_u(*_Z_envZ_memory,(ulong)(uVar1 - 0x11d));
        if ((uVar2 & 0xff) != 0x80) {
          iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 8));
          iVar6 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x124));
          uVar2 = _i32_load8_u(*_Z_envZ_memory,(ulong)(uint)(iVar6 + iVar4));
          if ((uVar2 & 0xff) == 0x3d) {
            iVar4 = _i32_load(*_Z_envZ_memory,(ulong)uVar8);
            store(uVar8,(iVar4 + 1));
          }
          uVar2 = _i32_load8_u(*_Z_envZ_memory,(ulong)(uVar1 - 0x11d));
          iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x128));
          store8((iVar4 + (uVar1 - 0x11c)),uVar2);
          iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x128));
          store((uVar1 - 0x128),(iVar4 + 1));
          iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x128));
          if (iVar4 == 4) {
            uVar2 = _i32_load8_u(*_Z_envZ_memory,(ulong)(uVar1 - 0x11c));
            uVar3 = _i32_load8_u(*_Z_envZ_memory,(ulong)(uVar1 - 0x11b));
            uVar5 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x118));
            store((uVar1 - 0x118),(uVar5 + 1));
            store8(uVar5, (ulong)((int)(uVar3 & 0xff) >> 4 | (uVar2 & 0xff) << 2));
            uVar2 = _i32_load8_u(*_Z_envZ_memory,(ulong)(uVar1 - 0x11b));
            uVar3 = _i32_load8_u(*_Z_envZ_memory,(ulong)(uVar1 - 0x11a));
            uVar5 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x118));
            _i32_store(*_Z_envZ_memory,(ulong)(uVar1 - 0x118),(ulong)(uVar5 + 1));
            _i32_store8(*_Z_envZ_memory,(ulong)uVar5,
                        (ulong)((int)(uVar3 & 0xff) >> 2 | (uVar2 & 0xff) << 4));
            uVar2 = _i32_load8_u(*_Z_envZ_memory,(ulong)(uVar1 - 0x11a));
            uVar3 = _i32_load8_u(*_Z_envZ_memory,(ulong)(uVar1 - 0x119));
            uVar5 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x118));
            _i32_store(*_Z_envZ_memory,(ulong)(uVar1 - 0x118),(ulong)(uVar5 + 1));
            _i32_store8(*_Z_envZ_memory,(ulong)uVar5,(ulong)(uVar3 & 0xff | (uVar2 & 0xff) << 6));
            _i32_store(*_Z_envZ_memory,(ulong)(uVar1 - 0x128),0);
            iVar4 = _i32_load(*_Z_envZ_memory,(ulong)uVar8);
            if (iVar4 != 0) {
              iVar4 = _i32_load(*_Z_envZ_memory,(ulong)uVar8);
              if (iVar4 == 1) {
                iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x118));
                _i32_store(*_Z_envZ_memory,(ulong)(uVar1 - 0x118),(ulong)(iVar4 - 1));
              }
              else {
                iVar4 = _i32_load(*_Z_envZ_memory,(ulong)uVar8);
                if (iVar4 != 2) {
                  uVar2 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x114));
                  _free((void *)(ulong)uVar2);
                  _i32_store(*_Z_envZ_memory,(ulong)(uVar1 - 4),0);
                  goto LAB_0001c0d7;
                }
                iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x118));
                _i32_store(*_Z_envZ_memory,(ulong)(uVar1 - 0x118),(ulong)(iVar4 - 2));
              }
              break;
            }
          }
        }
        iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x124));
        _i32_store(*_Z_envZ_memory,(ulong)(uVar1 - 0x124),(ulong)(iVar4 + 1));
      }
      iVar4 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x118));
      iVar6 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x114));
      uVar2 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x10));
      _i32_store(*_Z_envZ_memory,(ulong)uVar2,(ulong)(uint)(iVar4 - iVar6));
      uVar2 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 0x114));
      _i32_store(*_Z_envZ_memory,(ulong)(uVar1 - 4),(ulong)uVar2);
    }
  }
LAB_0001c0d7:
  uVar2 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 4));
    stack_base = uVar1;
  return uVar2;
}



ulong _f42(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  uint local_14;
  uint local_10;
  
  if (param_3 != 0) {
    iVar1 = param_1 + param_3;
    _i32_store8(*_Z_envZ_memory,(ulong)(iVar1 - 1),(ulong)param_2);
    _i32_store8(*_Z_envZ_memory,(ulong)param_1,(ulong)param_2);
    if (2 < param_3) {
      _i32_store8(*_Z_envZ_memory,(ulong)(iVar1 - 2),(ulong)param_2);
      _i32_store8(*_Z_envZ_memory,(ulong)(param_1 + 1),(ulong)param_2);
      _i32_store8(*_Z_envZ_memory,(ulong)(iVar1 - 3),(ulong)param_2);
      _i32_store8(*_Z_envZ_memory,(ulong)(param_1 + 2),(ulong)param_2);
      if (6 < param_3) {
        _i32_store8(*_Z_envZ_memory,(ulong)(iVar1 - 4),(ulong)param_2);
        _i32_store8(*_Z_envZ_memory,(ulong)(param_1 + 3),(ulong)param_2);
        if (8 < param_3) {
          uVar2 = (-param_1 & 3) + param_1;
          uVar3 = (param_2 & 0xff) * 0x1010101;
          _i32_store(*_Z_envZ_memory,(ulong)uVar2,(ulong)uVar3);
          local_14 = param_3 - (-param_1 & 3) & 0xfffffffc;
          iVar1 = local_14 + uVar2;
          _i32_store(*_Z_envZ_memory,(ulong)(iVar1 - 4),(ulong)uVar3);
          if (8 < local_14) {
            _i32_store(*_Z_envZ_memory,(ulong)(uVar2 + 8),(ulong)uVar3);
            _i32_store(*_Z_envZ_memory,(ulong)(uVar2 + 4),(ulong)uVar3);
            _i32_store(*_Z_envZ_memory,(ulong)(iVar1 - 8),(ulong)uVar3);
            _i32_store(*_Z_envZ_memory,(ulong)(iVar1 - 0xc),(ulong)uVar3);
            if (0x18 < local_14) {
              _i32_store(*_Z_envZ_memory,(ulong)(uVar2 + 0x18),(ulong)uVar3);
              _i32_store(*_Z_envZ_memory,(ulong)(uVar2 + 0x14),(ulong)uVar3);
              _i32_store(*_Z_envZ_memory,(ulong)(uVar2 + 0x10),(ulong)uVar3);
              _i32_store(*_Z_envZ_memory,(ulong)(uVar2 + 0xc),(ulong)uVar3);
              _i32_store(*_Z_envZ_memory,(ulong)(iVar1 - 0x10),(ulong)uVar3);
              _i32_store(*_Z_envZ_memory,(ulong)(iVar1 - 0x14),(ulong)uVar3);
              _i32_store(*_Z_envZ_memory,(ulong)(iVar1 - 0x18),(ulong)uVar3);
              _i32_store(*_Z_envZ_memory,(ulong)(iVar1 - 0x1c),(ulong)uVar3);
              local_10 = uVar2 & 4 | 0x18;
              local_14 = local_14 - local_10;
              if (0x1f < local_14) {
                uVar4 = CONCAT44(uVar3,uVar3);
                local_10 = local_10 + uVar2;
                do {
                  _i64_store(*_Z_envZ_memory,(ulong)(local_10 + 0x18),uVar4);
                  _i64_store(*_Z_envZ_memory,(ulong)(local_10 + 0x10),uVar4);
                  _i64_store(*_Z_envZ_memory,(ulong)(local_10 + 8),uVar4);
                  _i64_store(*_Z_envZ_memory,(ulong)local_10,uVar4);
                  local_10 = local_10 + 0x20;
                  local_14 = local_14 - 0x20;
                } while (0x1f < local_14);
              }
            }
          }
        }
      }
    }
  }
  return param_1; // wait does this do anything
  // looks like yes, just reusing that variable name.
}


ulong _f34(uint param_1,uint param_2,uint param_3)
{
  return _f25((ulong)param_1,(ulong)param_2,(ulong)param_3,1,2);
}


ulong _f25(uint param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  uint local_5c;
  uint local_58;
  int local_14;
  uint local_10;
  
  uVar1 = _g0;
  uVar5 = _g0 - 0xd0;
  _g0 = uVar5;
  _i32_store(*_Z_envZ_memory,(ulong)(uVar1 - 4),(ulong)param_3);
  local_14 = 0;
  _f42((ulong)(uVar1 - 0x30),0,0x28);
  uVar2 = _i32_load(*_Z_envZ_memory,(ulong)(uVar1 - 4));
  _i32_store(*_Z_envZ_memory,(ulong)(uVar1 - 8),(ulong)uVar2);
  iVar3 = _f26(0,(ulong)param_2,(ulong)(uVar1 - 8),(ulong)(uVar1 - 0x80),(ulong)(uVar1 - 0x30),
               (ulong)param_4,param_5);
  if (iVar3 < 0) {
    local_10 = 0xffffffff;
  }
  else {
    iVar3 = _i32_load(*_Z_envZ_memory,(ulong)(param_1 + 0x4c));
    if (-1 < iVar3) {
      local_14 = _f52((ulong)param_1);
    }
    uVar2 = _i32_load(*_Z_envZ_memory,(ulong)param_1);
    iVar3 = _i32_load8_s(*_Z_envZ_memory,(ulong)(param_1 + 0x4a));
    if (iVar3 < 1) {
      _i32_store(*_Z_envZ_memory,(ulong)param_1,(ulong)(uVar2 & 0xffffffdf));
    }
    iVar3 = _i32_load(*_Z_envZ_memory,(ulong)(param_1 + 0x30));
    if (iVar3 == 0) {
      _i32_store(*_Z_envZ_memory,(ulong)(param_1 + 0x30),0x50);
      _i32_store(*_Z_envZ_memory,(ulong)(param_1 + 0x10),(ulong)(uVar1 - 0x80));
      _i32_store(*_Z_envZ_memory,(ulong)(param_1 + 0x1c),(ulong)uVar5);
      _i32_store(*_Z_envZ_memory,(ulong)(param_1 + 0x14),(ulong)uVar5);
      uVar4 = _i32_load(*_Z_envZ_memory,(ulong)(param_1 + 0x2c));
      _i32_store(*_Z_envZ_memory,(ulong)(param_1 + 0x2c),(ulong)uVar5);
      local_58 = _f26((ulong)param_1,(ulong)param_2,(ulong)(uVar1 - 8),(ulong)(uVar1 - 0x80),
                      (ulong)(uVar1 - 0x30),(ulong)param_4,param_5);
      local_10 = local_58;
      if (uVar4 != 0) {
        uVar5 = _i32_load(*_Z_envZ_memory,(ulong)(param_1 + 0x24));
        bVar6 = false;
        if ((uVar5 < *(uint *)((long)*_Z_envZ_table + 0xc)) &&
           (bVar6 = false, *(long *)(**_Z_envZ_table + (ulong)uVar5 * 0x10 + 8) != 0)) {
          bVar6 = *(int *)(**_Z_envZ_table + (ulong)uVar5 * 0x10) == DAT_00024614;
        }
        if (bVar6) {
          (**(code **)(**_Z_envZ_table + (ulong)uVar5 * 0x10 + 8))((ulong)param_1,0,0);
        }
        else {
          _wasm_rt_trap(6);
        }
        _i32_store(*_Z_envZ_memory,(ulong)(param_1 + 0x30),0);
        _i32_store(*_Z_envZ_memory,(ulong)(param_1 + 0x2c),(ulong)uVar4);
        _i32_store(*_Z_envZ_memory,(ulong)(param_1 + 0x1c),0);
        _i32_store(*_Z_envZ_memory,(ulong)(param_1 + 0x10),0);
        iVar3 = _i32_load(*_Z_envZ_memory,(ulong)(param_1 + 0x14));
        _i32_store(*_Z_envZ_memory,(ulong)(param_1 + 0x14),0);
        if (iVar3 == 0) {
          local_58 = 0xffffffff;
        }
        local_10 = local_58;
      }
    }
    else {
      local_10 = _f26((ulong)param_1,(ulong)param_2,(ulong)(uVar1 - 8),(ulong)(uVar1 - 0x80),
                      (ulong)(uVar1 - 0x30),(ulong)param_4,param_5);
    }
    uVar5 = _i32_load(*_Z_envZ_memory,(ulong)param_1);
    _i32_store(*_Z_envZ_memory,(ulong)param_1,(ulong)(uVar2 & 0x20 | uVar5));
    if ((uVar5 & 0x20) == 0) {
      local_5c = local_10;
    }
    else {
      local_5c = 0xffffffff;
    }
    local_10 = local_5c;
    if (local_14 != 0) {
      _f53((ulong)param_1);
    }
  }
  _g0 = uVar1;
  return (ulong)local_10;
}


