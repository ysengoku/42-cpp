(On working)
# CPP Module04

## Subtype polymorphism 
In object-oriented programming,subtype polymorphism
ある1つの関数（メソッド）の呼び出しに対し、オブジェクト毎に異なる動作をすることをいいます

## Deep copy
Deep copy creates a new object copying the content of the source object.  
The copied object is independant of the original one. Even if we modify a value of attribute of the copy or delete it, there is no impact on the original one. 

## Abstract class
Abstract class is a base class which is not instantiable.
To create an abstruct class, we put 

## Interface
Interface is a pure abstruct class which has only pure virtual methodes.

```c++
// Virtual methode
virtual void  methode();

// Pure virtual methode
virtual void methode() = 0;
```

## References

[Subtyping - Wikipedia](https://en.wikipedia.org/wiki/Subtyping)
[Zenn: C++ クラス継承とポリモーフィズム](https://zenn.dev/rt3mis10/articles/2d9f5e8bcc06a7)
