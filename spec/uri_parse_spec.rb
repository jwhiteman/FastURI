require "spec_helper"

describe URIParse do
  describe "#parse" do
    it "parses relative netpaths" do
      up = URIParse.new("//foo-bar-baz")

      expect(up.parse).to eq({uri: "//foo-bar-baz"})
    end

    it "parses relative netpaths with domain labels" do
      up = URIParse.new("//foo.bar.baz")

      expect(up.parse).to eq({uri: "//foo.bar.baz"})
    end
  end
end

