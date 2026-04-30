#include "yaml-cpp/node/parse.h"

#include <fstream>
#include <sstream>

#include "nodebuilder.h"
#include "yaml-cpp/node/impl.h"
#include "yaml-cpp/node/node.h"
#include "yaml-cpp/parser.h"

namespace YAML {
Node Load(const std::string& input) {
  return Load(input, DuplicateKeyPolicy::KeepLast);
}

Node Load(
    const std::string& input,
    DuplicateKeyPolicy duplicateKeyPolicy) {
  std::stringstream stream(input);
  return Load(stream, duplicateKeyPolicy);
}

Node Load(const char* input) {
  return Load(input, DuplicateKeyPolicy::KeepLast);
}

Node Load(
    const char* input,
    DuplicateKeyPolicy duplicateKeyPolicy) {
  std::stringstream stream(input);
  return Load(stream, duplicateKeyPolicy);
}

Node Load(std::istream& input) {
  return Load(input, DuplicateKeyPolicy::KeepLast);
}

Node Load(
    std::istream& input,
    DuplicateKeyPolicy duplicateKeyPolicy) {
  Parser parser(input);
  NodeBuilder builder(duplicateKeyPolicy);
  if (!parser.HandleNextDocument(builder)) {
    return Node();
  }

  return builder.Root();
}

Node LoadFile(const std::string& filename) {
  return LoadFile(filename, DuplicateKeyPolicy::KeepLast);
}

Node LoadFile(
    const std::string& filename,
    DuplicateKeyPolicy duplicateKeyPolicy) {
  std::ifstream fin(filename);
  if (!fin) {
    throw BadFile(filename);
  }
  return Load(fin, duplicateKeyPolicy);
}

std::vector<Node> LoadAll(const std::string& input) {
  return LoadAll(input, DuplicateKeyPolicy::KeepLast);
}

std::vector<Node> LoadAll(
    const std::string& input,
    DuplicateKeyPolicy duplicateKeyPolicy) {
  std::stringstream stream(input);
  return LoadAll(stream, duplicateKeyPolicy);
}

std::vector<Node> LoadAll(const char* input) {
  return LoadAll(input, DuplicateKeyPolicy::KeepLast);
}

std::vector<Node> LoadAll(
    const char* input,
    DuplicateKeyPolicy duplicateKeyPolicy) {
  std::stringstream stream(input);
  return LoadAll(stream, duplicateKeyPolicy);
}

std::vector<Node> LoadAll(std::istream& input) {
  return LoadAll(input, DuplicateKeyPolicy::KeepLast);
}

std::vector<Node> LoadAll(
    std::istream& input,
    DuplicateKeyPolicy duplicateKeyPolicy) {
  std::vector<Node> docs;

  Parser parser(input);
  while (true) {
    NodeBuilder builder(duplicateKeyPolicy);
    if (!parser.HandleNextDocument(builder)) {
      break;
    }
    docs.push_back(builder.Root());
  }

  return docs;
}

std::vector<Node> LoadAllFromFile(const std::string& filename) {
  return LoadAllFromFile(filename, DuplicateKeyPolicy::KeepLast);
}

std::vector<Node> LoadAllFromFile(
    const std::string& filename,
    DuplicateKeyPolicy duplicateKeyPolicy) {
  std::ifstream fin(filename);
  if (!fin) {
    throw BadFile(filename);
  }
  return LoadAll(fin, duplicateKeyPolicy);
}
}  // namespace YAML
