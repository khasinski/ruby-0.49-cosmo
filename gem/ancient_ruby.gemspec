# frozen_string_literal: true

Gem::Specification.new do |spec|
  spec.name          = "ancient_ruby"
  spec.version       = "0.49.0"
  spec.authors       = ["Sam Westerman", "Chris Hasinski"]
  spec.email         = ["mail@sampersand.me", "krzysztof.hasinski@gmail.com"]

  spec.summary       = "Run Ruby 0.49 (1994) code from modern Ruby"
  spec.description   = "A gem that bundles Ruby 0.49, the oldest extant version of Ruby, " \
                       "as a universal Cosmopolitan binary. Evaluate ancient Ruby code " \
                       "from your modern Ruby applications."
  spec.homepage      = "https://github.com/sampersand/ruby-0.49"
  spec.license       = "MIT"
  spec.required_ruby_version = ">= 2.6.0"

  spec.metadata["source_code_uri"] = spec.homepage

  spec.files = Dir.chdir(__dir__) do
    Dir["{lib,exe}/**/*", "README.md", "LICENSE.txt"]
  end

  spec.bindir = "exe"
  spec.executables = ["ruby-0.49"]
  spec.require_paths = ["lib"]
end
