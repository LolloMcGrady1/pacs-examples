#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

// Attenzione MAI compilare gli header con template functions

namespace serialize
{
  //! Convert an std::vector<T>, where T is a trivial type,
  //!  to a vector of bytes that can be saved to a binary file
  //!  or transmitted through a channel such as a socket or
  //!  sent as an MPI message.
  template <class T>
  std::vector<unsigned char>
  write (const std::vector<T>& container)
  {

    size_t num = container.size();
    size_t size = num * sizeof(T);
    std::vector<unsigned char> res (size, 0);

    std::transform(container.begin(),container.end(),reinterpret_cast<T*>(&res[0]));


    return res;
  }

  //! Read in a std::vector<T>, where T is a trivial type,
  //!  from a vector of bytes.
  template <class T>
  void
  read (const std::vector<unsigned char>& data,
        std::vector<T> &container)
  {
    size_t numel = sizeof(T);
    size_t size = data.size()/numel;
    container.resize(size);
    std::transform(data.begin(),data.end(),container.begin(),reinterpret_cast<unsigned char*>(&container[0]));


  }

  //! Convert an std::map<F,S>, where F, S are trivial types,
  //!  to a vector of bytes that can be saved to a binary file
  //!  or transmitted through a channel such as a socket or
  //!  sent as an MPI message.
  // template <class F, class S>
  // std::vector<unsigned char>
  // write (const std::map<F,S>& container)
  // {
  //   std::vector<unsigned char> res (size, 0);
  //   return res;
  // }
  //
  // //! Read in an std::map<F,S>, where F, S are trivial types,
  // //!  from a vector of bytes.
  // template <class F, class S>
  // void
  // read (const std::vector<unsigned char>& data,
  //       std::map<F,S> &container)
  // {  }
  //
  // //! Convert an std::vector<std::map<F,S>>, where F, S
  // //!  are trivial types, to a vector of bytes that can
  // //!  be saved to a binary file or transmitted through
  // //!  a channel such as a socket or sent as an MPI message.
  // template <class F, class S>
  // std::vector<unsigned char>
  // write (const std::vector<std::map<F, S>>& container)
  // {
  //
  //   // sizeof (F) = nF
  //   // sizeof (S) = nS
  //   // sizeof (size_t) = nst
  //   // container.size () = N
  //   // container[i].size () = Ni
  //   //
  //   // memory layout:
  //   //   nst        N x nst       sum (Ni * (nF + nS),   i=0..N)
  //   // -------   ------------   ---------------------------------
  //   //    N       Ni, i=0..N          container[i],  i=0..N
  //   //
  //   std::vector<unsigned char> res;
  //   return res;
  // }
  //
  // //! Read in an std::vector<std::map<F,S>>, where F, S
  // //!  are trivial types, from a vector of bytes.
  // template <class F, class S>
  // void
  // read (const std::vector<unsigned char>& data,
  //       std::vector<std::map<F,S>> &container)
  // { }
  // }
}
