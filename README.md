Cxx-Snippets
============
Code Snippets of Code snippets of C++11, C++14, C++17.

## C++11

* **auto specifier**:

  Specifying that the type of the variable that is being declared will be automatically deduced from its initializer. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Thread/Async.cxx#L18)>

* **constexpr**:

  Specifying that the value of a variable or function can appear in constant expressions. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Thread/Async.cxx#L8)>
  
* **std::move**:

  Producing an xvalue expression that identifies its argument. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Thread/Thread.cxx#L22)>

* **std::atomic_flag**:

  An atomic boolean type. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Atomic/AtomicFlag.cxx#L8)>
  
* **std::array**:

  A container that encapsulates fixed size arrays. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Container/array.cxx#L6)>
  
* **std::forward_list**:

  A container that supports fast insertion and removal of elements from anywhere in the container. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Container/forward_list.cxx#L6)>
  
* **std::tuple**:

  A fixed-size collection of heterogeneous values. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Container/tuple.cxx#L7)>
  
* **std::shared_ptr**:

  A smart pointer that retains shared ownership of an object through a pointer. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/DynamicMemory/shared_ptr.cxx#L8)>
  
* **std::unique_ptr**:

  A smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/DynamicMemory/unique_ptr.cxx#L9)>
  
* **std::weak_ptr**:

  A smart pointer that holds a non-owning ("weak") reference to an object that is managed by `std::shared_ptr`. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/DynamicMemory/weak_ptr.cxx#L11)> 

* **Lambda expressions**:

  Constructs a closure: an unnamed function object capable of capturing variables in scope. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Functional/lambda.cxx#L10)>
  
* **std::async**:

  Running a function asynchronously. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Thread/Async.cxx#L16)>
  
* **std::thread**:

   A single thread of execution. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Thread/Thread.cxx#L17)>
   
* **std::mutex**:

  A synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Thread/Mutex.cxx#L11)>
  
* **std::condition_variable**:

   A synchronization primitive that can be used to block a thread, or multiple threads at the same time, until another thread both modifies a shared variable (the condition), and notifies the condition_variable. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Thread/ConditionVariable.cxx#L10)>

## C++14

* **Generic lambdas**:

  Allowing lambda function parameters to be declared with the auto type specifier. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Functional/lambda.cxx#L18)>

* **Lambda capture expressions**:

  Allowing lambda captured members to be initialized with arbitrary expressions. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Functional/lambda.cxx#L51)>

## C++17

* **std::string_view**

  A way to wrap an existing string in a NON-OWNING way, which is cheaper than `std::string` to constrct and copy. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/Container/string_view.cxx#L21)>

* **filesystem::space_info**:

  Space information on the filesystem. <[code](https://github.com/RincLiu/Cxx-Snippets/blob/master/IO/FileSystem.cxx#L7)>
