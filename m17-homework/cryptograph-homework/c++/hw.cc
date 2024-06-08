#include <sodium.h>
#include <iostream>
#include <iostream>

using namespace std;

#define MESSAGE (const unsigned char *)"test"
#define MESSAGE_LEN 4
#define CIPHERTEXT_LEN (crypto_box_MACBYTES + MESSAGE_LEN)

int main(int argc, char **argv)
{
  // Initialize libsodium.
  if (sodium_init() < 0)
  {
    std::cout << "libsodium is badly installed" << std::endl;
    return -1;
  }

  // Follow this example https://doc.libsodium.org/public-key_cryptography/authenticated_encryption

  // Your implementation goes here:
  // 1. Generate a secret and public key pair for the sender and one for the receiver.
  unsigned char sender_publickey[crypto_box_PUBLICKEYBYTES];
  unsigned char sender_secretkey[crypto_box_SECRETKEYBYTES];
  crypto_box_keypair(sender_publickey, sender_secretkey);

  unsigned char receiver_publickey[crypto_box_PUBLICKEYBYTES];
  unsigned char receiver_secretkey[crypto_box_SECRETKEYBYTES];
  crypto_box_keypair(receiver_publickey, receiver_secretkey);

  // 2. Define the message you want to encrypt including its length.
  // Done in definition macros

  // 3. Allocate a buffer for the nonce and cipher text.
  unsigned char nonce[crypto_box_NONCEBYTES];
  unsigned char ciphertext[CIPHERTEXT_LEN];
  randombytes_buf(nonce, sizeof nonce);

  // 4. use `crypto_box_easy` to encrypt, then `crypto_box_open_easy` to decrypt.
  if (crypto_box_easy(ciphertext, MESSAGE, MESSAGE_LEN, nonce,
                      receiver_publickey, sender_secretkey) != 0)
  {
    /* error */
    cout << "Issue with encryption" << endl;
  }

  cout << ciphertext << endl;

  // ciphertext[0] = 100;

  unsigned char decrypted[MESSAGE_LEN];
  if (crypto_box_open_easy(decrypted, ciphertext, CIPHERTEXT_LEN, nonce,
                           sender_publickey, receiver_secretkey) != 0)
  {
    /* message for Bob pretending to be from Alice has been forged! */
    cout << "Message has been forged" << endl;
  }

  // 5. print the result and validate it is correct.
  cout << decrypted << endl;

  return 0;
}
