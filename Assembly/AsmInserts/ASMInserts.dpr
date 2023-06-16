Program ASMInserts;

{$APPTYPE CONSOLE}

Const
  N = 9;

Type
  TArray = array [0..N] of Integer;

Var
  A: Tarray = (32,254,2,134,562,76,83,228,8,255);
  B: Tarray = (2,34,32,1488,75,8,83,23,18,255);
  C: TArray;
  I,J: Integer;

Begin

{
  for I := low(A) to high(A) do
  begin
    writeln('Enter A[',I,']');
    readln(A[I]);
  end;


  for I := low(B) to high(B) do
  begin
    writeln('Enter B[',I,']');
    readln(B[I]);
  end;
}

  writeln('A:');
  for I := low(A) to high(A) do
    write(A[I],' ');
  writeln;

  writeln('B:');
  for I := low(B) to high(B) do
    write(B[I],' ');
  writeln;

  I := 0;

  asm

      // Prepareing before entering the cycle
      // ebp - A array iterator
      // edi - counter of repeats
      // ebx - C array iterator
      // C is for the elements that repeat
      xor ebp,ebp
      xor edi,edi
      xor ebx,ebx

    // beginning of the cycle
    @Start:

      // Set zero for esi
      // esi - B array iterator
      xor esi,esi

      // put the first element into the eax
      // to compare with B array elements
      mov eax,dword [A + ebp]

    // start search
    @Search:

      // compare element of A array with every element of B array
      cmp eax, dword [B + esi]
      jne @Iteration

      // increment the counter and write the equal element into C array
      mov dword [C + ebx],eax
      inc edi
      add ebx,4

    // Modifying iterators
    @Iteration:
      add esi,4
      cmp esi,40d
      jne @Search

      add ebp,4
      cmp ebp,40d
      jne @Start

      mov dword [I],edi
  end;

  writeln('Number of repeats: ',I);

  J := 0;

  writeln('Elements that repeat:');
  while J < I do
  begin
    write(C[J],' ');
    Inc(J);
  end;

  readln;
end.

